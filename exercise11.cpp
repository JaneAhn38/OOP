#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

const int map_row_size = 20;
const int map_column_size = 40;

char bfs_map[map_row_size][map_column_size];

char map[map_row_size][map_column_size] = {
    "# #####################################",
    "#    #                    #           #",
    "#              #          #            ",
    "####    ####   ####     ###     ## ####",
    "#                                     #",
    "#    ###       ####        ##     #   #",
    "#    ###       #           #####      #",
    "# #    #  #    #   ####        #      #",
    "# #    #  #     #     #    #   #    ###",
    "# ######  #     #     #    #   ###    #",
    "#            ####             #       #",
    "#  ####         ##         ####       #",
    "#                    ##               #",
    "####   ##     ##     ##       ###  ## #",
    "       #         #        #     #     #",
    "##    #   ####   ##  #  ####    #     #",
    "#     ##                   #         ##",
    "###    #     ######        ###        #",
    "#                ##                ####",
    "################################ ######"
};

void display_map() {
    for (int i = 0; i < map_row_size; i++) {
        printf("%s\n", map[i]);
    }
}

void gotoxy(short x, short y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };
    SetConsoleCursorPosition(hStdout, position);
}

struct path_node { int x, y, parent_id; };
struct position { int x, y; };

vector<path_node> bfs_list;
vector<position>  enemy_path;

void add_new_node_to_bfs_list(int x, int y, int id) {
    path_node node;

    // 배열 범위 체크
    if (x < 0 || x >= map_column_size || y < 0 || y >= map_row_size) return;

    if (bfs_map[y][x] == ' ' || bfs_map[y][x] == '.') {
        bfs_map[y][x] = '#';      // 방문 표시
        node.x = x; node.y = y; node.parent_id = id;
        bfs_list.push_back(node);
    }
}

void FindPath(int ex, int ey, int x, int y) {
    path_node node; position pos;
    int j, k, index;

    for (k = 0; k < map_row_size; k++)
        for (j = 0; j < map_column_size; j++)
            bfs_map[k][j] = map[k][j];

    bfs_list.clear();
    node.x = ex; node.y = ey; node.parent_id = -1;
    bfs_list.push_back(node);
    index = 0;

    while (index < (int)bfs_list.size()) {
        if (bfs_list[index].x == x && bfs_list[index].y == y) {
            enemy_path.clear();
            while (bfs_list[index].parent_id != -1) {
                pos.x = bfs_list[index].x;
                pos.y = bfs_list[index].y;
                enemy_path.push_back(pos);
                index = bfs_list[index].parent_id;
            }
            goto U_Exit;
        }

        add_new_node_to_bfs_list(bfs_list[index].x, bfs_list[index].y - 1, index);
        add_new_node_to_bfs_list(bfs_list[index].x, bfs_list[index].y + 1, index);
        add_new_node_to_bfs_list(bfs_list[index].x - 1, bfs_list[index].y, index);
        add_new_node_to_bfs_list(bfs_list[index].x + 1, bfs_list[index].y, index);
        index++;
    }

U_Exit:
    bfs_list.clear();
}

int main() {
    bool game_is_running_now = true;

    int x = 15, y = 16, old_x, old_y;
    int ex = 2, ey = 2;

    int game_speed = 3, score = 0, count = 0;
    char player = 'P', enemy = 'E';

    // 포탈 중복 진입 방지용 플래그
    bool portal_cooldown = false;

    // 포탈 좌표 (맵 상의 인덱스 기준)
    // 포탈1: R3 오른쪽 끝 → R15 C1, 반대로는 R15 C1에서 ← 누를 때
    const int PORTAL1_SRC_X = 38; // row 2의 제일 오른쪽 공백
    const int PORTAL1_SRC_Y = 2;
    const int PORTAL1_DST_X = 0;  // row 14의 첫 칸(공백)
    const int PORTAL1_DST_Y = 14;

    // 포탈2: R20 C33 → R1 C2, 반대로는 R1 C2에서 ↑ 누를 때
    const int PORTAL2_SRC_X = 32; // 마지막 줄의 공백 칸
    const int PORTAL2_SRC_Y = 19;
    const int PORTAL2_DST_X = 1;  // 첫 줄의 두 번째 칸(공백)
    const int PORTAL2_DST_Y = 0;

    system("cls");
    display_map();
    gotoxy(x, y); cout << player;
    FindPath(ex, ey, x, y);

    while (game_is_running_now) {
        old_x = x;
        old_y = y;

        // ======================
        //  플레이어 이동 / 포탈 / 벽 밀기
        // ======================
        if (!portal_cooldown && (GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
            // 포탈1 입구: R3 오른쪽 끝에서 → 키 → R15 C1
            if (y == PORTAL1_SRC_Y && x == PORTAL1_SRC_X) {
                x = PORTAL1_DST_X;
                y = PORTAL1_DST_Y;
                portal_cooldown = true;
            }
            else {
                int nx = x + 1, ny = y;
                if (nx < map_column_size) {
                    char c1 = map[ny][nx];

                    if (c1 == '.') {          // 코인
                        x = nx; score++;
                    }
                    else if (c1 == ' ') {   // 빈칸
                        x = nx;
                    }
                    else if (c1 == '#') {   // 벽 → 밀기 시도
                        int wx_old = nx;          // 현재 벽 위치
                        int wy_old = ny;
                        int wx_new = x + 2;       // 벽이 밀릴 위치
                        int wy_new = y;

                        if (wx_new < map_column_size &&
                            map[wy_new][wx_new] == ' ') {

                            // 벽 데이터 이동
                            map[wy_old][wx_old] = ' ';
                            map[wy_new][wx_new] = '#';

                            // 콘솔에 벽 갱신
                            gotoxy(wx_old, wy_old); cout << ' ';
                            gotoxy(wx_new, wy_new); cout << '#';

                            // 플레이어도 한 칸 앞으로 (벽이 있던 자리로)
                            x = nx;
                        }
                    }
                }
            }
        }
        else if (!portal_cooldown && (GetAsyncKeyState(VK_LEFT) & 0x8000)) {
            // 포탈1 출구: R15 C1에서 ← 키 → 다시 R3 끝
            if (y == PORTAL1_DST_Y && x == PORTAL1_DST_X) {
                x = PORTAL1_SRC_X;
                y = PORTAL1_SRC_Y;
                portal_cooldown = true;
            }
            else {
                int nx = x - 1, ny = y;
                if (nx >= 0) {
                    char c1 = map[ny][nx];

                    if (c1 == '.') {
                        x = nx; score++;
                    }
                    else if (c1 == ' ') {
                        x = nx;
                    }
                    else if (c1 == '#') {
                        int wx_old = nx;
                        int wy_old = ny;
                        int wx_new = x - 2;
                        int wy_new = y;

                        if (wx_new >= 0 &&
                            map[wy_new][wx_new] == ' ') {

                            map[wy_old][wx_old] = ' ';
                            map[wy_new][wx_new] = '#';

                            gotoxy(wx_old, wy_old); cout << ' ';
                            gotoxy(wx_new, wy_new); cout << '#';

                            x = nx;
                        }
                    }
                }
            }
        }
        else if (!portal_cooldown && (GetAsyncKeyState(VK_DOWN) & 0x8000)) {
            // 포탈2 입구: R20 C33에서 ↓ → R1 C2
            if (y == PORTAL2_SRC_Y && x == PORTAL2_SRC_X) {
                x = PORTAL2_DST_X;
                y = PORTAL2_DST_Y;
                portal_cooldown = true;
            }
            else {
                int nx = x, ny = y + 1;
                if (ny < map_row_size) {
                    char c1 = map[ny][nx];

                    if (c1 == '.') {
                        y = ny; score++;
                    }
                    else if (c1 == ' ') {
                        y = ny;
                    }
                    else if (c1 == '#') {
                        int wx_old = nx;
                        int wy_old = ny;
                        int wx_new = x;
                        int wy_new = y + 2;

                        if (wy_new < map_row_size &&
                            map[wy_new][wx_new] == ' ') {

                            map[wy_old][wx_old] = ' ';
                            map[wy_new][wx_new] = '#';

                            gotoxy(wx_old, wy_old); cout << ' ';
                            gotoxy(wx_new, wy_new); cout << '#';

                            y = ny;
                        }
                    }
                }
            }
        }
        else if (!portal_cooldown && (GetAsyncKeyState(VK_UP) & 0x8000)) {
            // 포탈2 출구: R1 C2에서 ↑ → R20 C33
            if (y == PORTAL2_DST_Y && x == PORTAL2_DST_X) {
                x = PORTAL2_SRC_X;
                y = PORTAL2_SRC_Y;
                portal_cooldown = true;
            }
            else {
                int nx = x, ny = y - 1;
                if (ny >= 0) {
                    char c1 = map[ny][nx];

                    if (c1 == '.') {
                        y = ny; score++;
                    }
                    else if (c1 == ' ') {
                        y = ny;
                    }
                    else if (c1 == '#') {
                        int wx_old = nx;
                        int wy_old = ny;
                        int wx_new = x;
                        int wy_new = y - 2;

                        if (wy_new >= 0 &&
                            map[wy_new][wx_new] == ' ') {

                            map[wy_old][wx_old] = ' ';
                            map[wy_new][wx_new] = '#';

                            gotoxy(wx_old, wy_old); cout << ' ';
                            gotoxy(wx_new, wy_new); cout << '#';

                            y = ny;
                        }
                    }
                }
            }
        }

        // 방향키를 전부 뗐을 때 포탈 쿨다운 해제
        if (!(GetAsyncKeyState(VK_RIGHT) & 0x8000) &&
            !(GetAsyncKeyState(VK_LEFT) & 0x8000) &&
            !(GetAsyncKeyState(VK_UP) & 0x8000) &&
            !(GetAsyncKeyState(VK_DOWN) & 0x8000)) {
            portal_cooldown = false;
        }

        // ======================
        //  플레이어 이동 후 처리
        // ======================
        if (old_x != x || old_y != y) {
            FindPath(ex, ey, x, y);

            gotoxy(old_x, old_y); cout << " ";
            gotoxy(x, y);         cout << player;
        }

        // ======================
        //  적 이동 / 점수 출력
        // ======================
        map[ey][ex] = '.';
        gotoxy(ex, ey); cout << ".";

        if (count % game_speed == 0 && enemy_path.size() != 0) {
            ex = enemy_path.back().x;
            ey = enemy_path.back().y;
            enemy_path.pop_back();
        }

        gotoxy(ex, ey); cout << enemy;

        if (ex == x && ey == y) break;

        gotoxy(45, 1); cout << "SCORE = " << score;

        Sleep(100);
        count++;
        if (count == 10000) count = 0;
    }

    system("cls");
    cout << "GAME OVER" << endl << endl;
    cout << "Your Score = " << score << endl << endl << endl << endl;
    system("pause");
    return 0;
}
