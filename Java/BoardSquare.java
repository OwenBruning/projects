/**
The BoardSquare class represents a square on the board.
*/
public class BoardSquare
{
  private Card card; //Declare some private variables which will serve as the instance data for each board square.
  private int row;
  private int col;
  private boolean isSelected = false;
  
  /**
  The constructor creates a board square and initializes the card, row, and col variables.
  @param card The card
  @param row The row
  @param col The column
  */
  public BoardSquare(Card card, int row, int col)
  {
    this.card = card;
    this.row = row;
    this.col = col;
  }
  /**
  The getCard method returns the card.
  @return The card
  */
  public Card getCard()
  {
    return card;
  }
  /**
  The getRow method returns the row.
  @return The row
  */
  public int getRow()
  {
    return row;
  }
  /**
  The getCol method returns the column.
  @return The column
  */
  public int getCol()
  {
    return col;
  }
  /**
  The getIsSelected method returns true if the board square is selected.
  @return True if the board square is selected
  */
  public boolean getIsSelected()
  {
    return isSelected;
  }
  /**
  The setCard method sets the card.
  @param card The card
  */
  public void setCard(Card card)
  {
    this.card = card;
  }
  /**
  The setRow method sets the row.
  @param row The row
  */
  public void setRow(int row)
  {
    this.row = row;
  }
  /**
  The setCol method sets the column.
  @param col The column
  */
  public void setCol(int col)
  {
    this.col = col;
  }
  /**
  The setIsSelected method sets the isSelected variable.
  @param isSelected True if the board square is selected
  */
  public void setIsSelected(boolean isSelected)
  {
    this.isSelected = isSelected;
  }
  /**
  The toString method returns a string representation of the card that the board square contains.
  @return A string representation of the card that the board square contains
  */
  @Override
  public String toString()
  {
    return getCard().toString();
  }
}