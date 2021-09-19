import java.util.ArrayList; //This is required in order to create instances of the ArrayList class.
/**
The Board class represents the board.
*/
public class Board
{
  ArrayList<BoardSquare> boardRow;
  ArrayList<ArrayList<BoardSquare>> board;
  private int add3Counter = 0; //Declare a private variable for the board.
  
  /**
  The constructor creates the board and initializes the boardRow and board variables.
  @param deck The deck
  */
  public Board(Deck deck)
  {
    boardRow = new ArrayList<>();
    board = new ArrayList<>();
    for (int rows = 0; rows < 3; rows++)
    {
      for (int cols = 0; cols < 4; cols++)
      {
        BoardSquare b = new BoardSquare(deck.getTopCard(), rows, cols);
        boardRow.add(b);
        board.add(boardRow);
      }
    }  
  }
  /**
  The replaceCard method replaces a card on the board with the specified card at the specified position.
  @param card The card
  @param row The row
  @param col The column
  */
  public void replaceCard(Card card, int row, int col)
  {  
    BoardSquare b = getBoardSquare(row, col);
    b.setCard(card);
  }
  /**
  The getBoardSquare method returns the board square at the specified position.
  @param row The row
  @param col The column
  @return The board square
  */
  public BoardSquare getBoardSquare(int row, int col)
  {
    if (row == 0 && col == 0)
      return boardRow.get(0);
    if (row == 0 && col == 1)
      return boardRow.get(1);
    if (row == 0 && col == 2)
      return boardRow.get(2);
    if (row == 0 && col == 3)
      return boardRow.get(3);
    if (row == 1 && col == 0)
      return boardRow.get(4);
    if (row == 1 && col == 1)
      return boardRow.get(5);
    if (row == 1 && col == 2)
      return boardRow.get(6);
    if (row == 1 && col == 3)
      return boardRow.get(7);
    if (row == 2 && col == 0)
      return boardRow.get(8);
    if (row == 2 && col == 1)
      return boardRow.get(9);
    if (row == 2 && col == 2)
      return boardRow.get(10);
    if (row == 2 && col == 3)
      return boardRow.get(11);
    if (row == 0 && col == 4)
      return boardRow.get(12);
    if (row == 1 && col == 4)
      return boardRow.get(13);
    if (row == 2 && col == 4)
      return boardRow.get(14);
    if (row == 0 && col == 5)
      return boardRow.get(15);
    if (row == 1 && col == 5)
      return boardRow.get(16);
    if (row == 2 && col == 5)
      return boardRow.get(17);
    else
      return boardRow.get(0);
  }
  /**
  The add3 method adds 3 cards to the board.
  @param deck The deck
  */
  public void add3(Deck deck)
  {
    for (int i = 0; i < 3; i++)
    {
      BoardSquare b = new BoardSquare(deck.getTopCard(), i, numCols());
      boardRow.add(b);
      board.add(boardRow);
    }
    add3Counter++; 
  }
  /**
  The getCard method returns the card at the specified position.
  @param row The row
  @param col The column
  @return The card
  */
  public Card getCard(int row, int col)
  {
    return getBoardSquare(row, col).getCard();        
  }
  /**
  The numRows method returns the number of rows.
  @return The number of rows
  */
  public int numRows()
  {
    return 3;
  }
  /**
  The numCols method returns the number of columns.
  @return The number of columns
  */
  public int numCols()
  {
    return 4 + add3Counter;
  }
  /**
  The toString method returns a string representation of the board.
  @return A string representation of the board
  */
  @Override
  public String toString()
  {
    String result = "";
    if (numCols() == 4)
      for (int rows = 0; rows < 3; rows++)
        result += String.format("%-28s   %-28s   %-28s   %-28s\n", getCard(rows, 0), getCard(rows, 1), getCard(rows, 2), getCard(rows, 3));
    else if (numCols() == 5)
      for (int rows = 0; rows < 3; rows++)
        result += String.format("%-28s   %-28s   %-28s   %-28s   %-28s\n", getCard(rows, 0), getCard(rows, 1), getCard(rows, 2), getCard(rows, 3), getCard(rows, 4));
    else if (numCols() == 6)
      for (int rows = 0; rows < 3; rows++)
        result += String.format("%-28s   %-28s   %-28s   %-28s   %-28s   %-28s\n", getCard(rows, 0), getCard(rows, 1), getCard(rows, 2), getCard(rows, 3), getCard(rows, 4), getCard(rows, 5));
    return result;
  }
}