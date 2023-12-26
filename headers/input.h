#ifndef INPUT_H
#define INPUT_H
enum class PlayerInput{
    MoveLeft,
    MoveRight,
    MoveUp,
    MoveDown,
    MoveUpLeft,
    MoveUpRight,
    MoveDownLeft,
    MoveDownRight,
    OpenInventory,
    OpenEquipMenu,
    Wait
};
class InputHandler {
    public:
        // Constructor
        InputHandler();

        // Destructor
        ~InputHandler();

        // Method to process input and return PlayerInput enum
#ifdef USE_SDL
    PlayerInput getInput(SDL_Event& event);
#endif

#ifdef USE_NCURSES
    PlayerInput getInput();
#endif
    private:
};

#endif // INPUT_H