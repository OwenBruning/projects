import java.util.ArrayList;
/**
The Game class represents the game.
*/
public class Game
{
  private ArrayList<BoardSquare> selected;
  private Deck deck;
  private Board b;
  
  /**
  The constructor creates a game and initializes the variables.
  */
  public Game()
  {
    selected = new ArrayList<>();
    deck = new Deck();
    deck.shuffle();
    b = new Board(deck);
  }
  /**
  The outOfCards method returns true if there are no more cards in the deck.
  @return True if there are no more cards in the deck
  */
  public boolean outOfCards()
  {
    return deck.isEmpty();
  }
  /**
  The addToSelected method adds the board square at the specified position to the array list of board squares.
  @param row The row
  @param col The column
  */
  public void addToSelected(int row, int col)
  {
    selected.add(b.getBoardSquare(row, col));
  }
  /**
  The numSelected method returns the number of selected board squares.
  @return The number of selected board squares
  */
  public int numSelected()
  {
    return selected.size();
  }
  /**
  The testSelected method replaces the cards if the cards are a set or unselects the cards if the cards are not a set.
  */
  public void testSelected()
  {
    if (Card.isSet(selected.get(0).getCard(), selected.get(1).getCard(), selected.get(2).getCard()))
    {
      System.out.println("set!: " + selected.get(0) + " " + selected.get(1) + " " + selected.get(2));
      for (int i = selected.size()-1; i >= 0; i--)
      {
        selected.get(i).setCard(deck.getTopCard());
        selected.remove(i);
      }
    }
    else
    {
      System.out.println("not a set!: " + selected.get(0) + " " + selected.get(1) + " " + selected.get(2));
      for (int i = selected.size()-1; i >= 0; i--)
        selected.remove(i);
    }
  }
  /**
  The removeSelected method removes the board square at the specified position from the array list of board squares.
  @param row The row
  @param col The column
  */
  public void removeSelected(int row, int col)
  {
    for (int i = 0; i < selected.size(); i++)
      if (selected.get(i).getRow() == row && selected.get(i).getCol() == col)
        selected.remove(i);
  }
  /**
  The add3 method adds 3 cards to the board.
  */
  public void add3()
  {
    b.add3(deck);
  }
  /**
  The getSelected method returns the array list of board squares which is called selected.
  @return The array list of board squares which is called selected
  */
  public ArrayList<BoardSquare> getSelected()
  {
    return selected;
  }
  /**
  The toString method returns a string representation of the game.
  @return A string representation of the game
  */
  @Override
  public String toString()
  {
    return b.toString();
  }
}
