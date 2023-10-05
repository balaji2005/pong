#include <simplecpp>

bool GAME_OVER = false;
const double scale = 3;

vector<Polygon> number(double x, double y) {

    vector<Polygon> blocks;

    double hor_positions[6][2] = {{-5*scale, 0}, {-4*scale, scale}, {4*scale, scale}, {5*scale, 0}, {4*scale, -scale}, {-4*scale, -scale}};
    double ver_positions[6][2] = {{0, 5*scale}, {scale, 4*scale}, {scale, -4*scale}, {0, -5*scale}, {-scale, -4*scale}, {-scale, 4*scale}};

    // double positions[6][2] = {{-5*scale, 5*scale + 2}, {-4*scale, scale + 5*scale + 2}, {4*scale, scale + 5*scale + 2}, {5*scale, 5*scale + 2}, {4*scale, -scale + 5*scale + 2}, {-4*scale, -scale + 5*scale + 2}};
    blocks.push_back(Polygon(x, y - 10*scale - 2, hor_positions, 6));
    blocks.push_back(Polygon(x, y, hor_positions, 6));
    blocks.push_back(Polygon(x, y + 10*scale + 2, hor_positions, 6));
    blocks.push_back(Polygon(x - 5*scale - 1, y - 5*scale - 1, ver_positions, 6));
    blocks.push_back(Polygon(x + 5*scale + 1, y - 5*scale - 1, ver_positions, 6));
    blocks.push_back(Polygon(x - 5*scale - 1, y + 5*scale + 1, ver_positions, 6));
    blocks.push_back(Polygon(x + 5*scale + 1, y + 5*scale + 1, ver_positions, 6));
    
    return blocks;
}

// void display(double x, double y, int number) {
//     vector<Polygon> digit = number(x, y);
//     switch(number) {
//         case 0:
//             Polygon block = digit[0];
//             block.setFill(true);
//             block.setColor(COLOR("white"));
//             block.imprint();

//             for (int i=2; i<=6; i++) {
//                 block = digit[i];
//                 block.setFill(true);
//                 block.setColor(COLOR("white"));
//                 block.imprint();
//             }
//             break;
//         case 1:
//             block = digit[4];
//             block.setFill(true);
//             block.setColor(COLOR("white"));
//             block.imprint();

//             block = digit[6];
//             block.setFill(true);
//             block.setColor(COLOR("white"));
//             block.imprint();
//             break;
//         default:
//             for(Polygon block: digit) {
//                 block.setFill(true);
//                 block.setColor(COLOR("white"));
//                 block.imprint();
//             }
//     }
// }

// Function to create game outline
void reset() {
    // Background
    Rectangle board(500, 250, 1000, 500);
    board.setFill(true);
    board.setColor(COLOR("black"));
    board.imprint();

    // Border
    board.reset(500, 250, 920, 420);
    board.setColor(COLOR("white"));
    board.imprint();

    board.reset(500, 250, 900, 400);
    board.setColor(COLOR("black"));
    board.imprint();

    // Ball
    // Circle ball(500, 250, 10);
    // ball.setFill(true);
    // ball.setColor(COLOR("white"));
    // ball.imprint();

    // Player
    Rectangle player(900, 250, 10, 50);
    player.setFill(true);
    player.setColor(COLOR("white"));
    player.imprint();

    // Test
    // double positions[6][2] = {{0, 5*scale}, {scale, 4*scale}, {scale, -4*scale}, {0, -5*scale}, {-scale, -4*scale}, {-scale, 4*scale}};
    // Polygon block(500, 250, positions, 6);
    // block.setFill(true);
    // block.setColor(COLOR("white"));
    // block.imprint();

    vector<Polygon> digit = number(400, 300);
    for (Polygon block: digit) {
        block.setFill(true);
        block.setColor(COLOR("white"));
        block.imprint();
    }
    // display(400, 300, 0);
    wait(5);
}

// Function to handle user inputs

// Function to handle