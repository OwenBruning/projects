import java.util.ArrayList; //This is required in order to create instances of the ArrayList class.
import java.util.Random; //This is required in order to create instances of the Random class.
/**
The Deck class represents a deck that contains 81 cards.
*/
public class Deck
{
  ArrayList<Card> deck; //Create an object called deck.
  Random rand = new Random(); //Create an object called rand.
  private int count = 0;
  
  /**
  The constructor creates a deck and initializes the deck to have 81 cards.
  */
  public Deck()
  {
    deck = new ArrayList<>();
    for (Card.Shape s : Card.Shape.values())
      for (Card.Color c : Card.Color.values())
        for (Card.Number n : Card.Number.values())
          for (Card.Fill f : Card.Fill.values())
          {
            Card card = new Card(s, c, n, f);
            deck.add(card);
          }
  }
  /**
  The shuffle method randomly shuffles the cards in the deck.
  */
  public void shuffle()
  {
    ArrayList<Card> tempDeck = new ArrayList<>();
    for (int i = 0; i < 81; i++)
    {
      int index = rand.nextInt(deck.size());
      tempDeck.add(deck.get(index));
      deck.remove(index);
    }
    deck = tempDeck;
  }
  /**
  The toString method returns a string representation of the deck.
  @return A string representation of the deck
  */
  public String toString()
  {
    String cards = "";
    for (Card c : deck)
      cards += ", " + c.toString();
    return cards;
  }
  /**
  The isEmpty method checks to determine whether or not the deck is empty.
  @return True if the deck is empty
  */
  public boolean isEmpty()
  {
    if (count == 81)
      return true;
    return false;
  }
  /**
  The getTopCard method returns a reference to the card being removed from the deck.
  @return A reference to the card being removed from the deck
  */
  public Card getTopCard()
  { 
    count++;
    return deck.get(81-count);
  }
  public int getCount()
  {
    return count;
  }
}