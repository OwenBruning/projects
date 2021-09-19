/**
The Card class represents a card, which has 4 features.
*/
public class Card
{
  public enum Shape {OVAL, SQUIGGLE, DIAMOND}; //Use enums to declare new types to represent the 4 features.
  public enum Color {RED, PURPLE, GREEN};
  public enum Number {ONE, TWO, THREE};
  public enum Fill {SOLID, HATCHED, OUTLINE};
  private Shape s; //Declare some private variables which will serve as the instance data for each card.
  private Color c;
  private Number n;
  private Fill f;
  
  /**
  The constructor creates a Card object and initializes the 4 features.
  @param s The shape
  @param c The color
  @param n The number
  @param f The fill
  */
  public Card(Shape s, Color c, Number n, Fill f)
  {
    this.s = s;
    this.c = c;
    this.n = n;
    this.f = f;
  }
  /**
  The toString method returns a string representation of the card.
  @return A string representation of the card
  */
  public String toString()
  {
    return n + "_" + c + "_" + s + "_" + f;
  }
  /**
  The isSet method determines if 3 cards form a set.
  @param c1 The first card in the potential set
  @param c2 The second card in the potential set
  @param c3 The third card in the potential set
  @return True if the 3 cards form a set
  */
  public static boolean isSet(Card c1, Card c2, Card c3)
  {
    if ((((c1.s == c2.s) && (c2.s == c3.s)) || ((c1.s != c2.s) && (c2.s != c3.s) && (c1.s != c3.s))) && (((c1.c == c2.c) && (c2.c == c3.c)) || ((c1.c != c2.c) && (c2.c != c3.c) && (c1.c != c3.c))) && (((c1.n == c2.n) && (c2.n == c3.n)) || ((c1.n != c2.n) && (c2.n != c3.n) && (c1.n != c3.n))) && (((c1.f == c2.f) && (c2.f == c3.f)) || ((c1.f != c2.f) && (c2.f != c3.f) && (c1.f != c3.f))))  
      return true;
    return false;
  }
  public Shape getShape()
  {
    return s;
  }
  public Color getColor()
  {
    return c;
  }
  public Number getNumber()
  {
    return n;
  }
  public Fill getFill()
  {
    return f;
  }
}