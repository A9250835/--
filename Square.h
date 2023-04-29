//紀錄格子狀態
#ifndef Square_h
#define Square_h
class Square
{
  public:
    Square();
    bool hasMine(); // 回傳是否為地雷
    bool isRevealed(); // 回傳是否已被翻開
    bool isFlagged(); // 回傳是否被標記為地雷
    int getNumAdjacentMines(); // 回傳鄰近格子中地雷的數量
  
    void setMine(bool mine); // 設定是否為地雷
    void setRevealed(bool revealed); // 設定是否已被翻開
    void setFlagged(bool flagged); // 設定是否被標記為地雷
    void setNumAdjacentMines(int num); // 設定鄰近格子中地雷的數量
  
  private:
    bool isMine;//是否為地雷
    bool isRevealed;//是否被翻開
    bool isFlagged;//是否被做記號
    int numMine;//附近地雷數量
};

#endif
