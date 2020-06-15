

#ifndef LOL_PACBOARD_H
#define LOL_PACBOARD_H


struct field
{
    bool hasPacman;
    bool hasGhost;
    bool hasFood;
    bool hasTrap;
    bool hasPremiumFood;
    bool isEmpty;
};

class PacBoard
{
    field board[100][100];
    int height;
    int width;
   //void for_draw(int row, int col, int rowKoniec,int colKoniec);
   // void erase(int row, int col, int rowKoniec,int colKoniec);
    void placeFoodOnBoard();
public:
    PacBoard();
    void Debug_Display() const;
    int getWidth() const;
    int getHeight() const;
    char getCharInfo(int x,int y) const;
   void setFoodFalse(int row,int col);
   void DefaultSettings();
   void setPremiumFoodFalse(int row, int col);
};


#endif //LOL_PACBOARD_H
