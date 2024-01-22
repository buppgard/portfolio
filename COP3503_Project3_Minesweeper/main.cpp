#include "GUI.h"
#include "Board.h"

int main() {
    Board board;
    GUI gui(board.GetOverallWidth(), board.GetOverallHeight(), "Ben's Minesweeper");
    while (gui.IsOpen()) {
        while(gui.Event()) {
            if (gui.EventCloseWindow()) {
                gui.Close();
            }
            else if (gui.EventMouseClick()) {
                board.MouseClick(gui);
            }
        }
        gui.Clear();
        board.Draw(gui);
        gui.Display();
    }
    return 0;
}
