import java.util.ArrayList;
public class BoardTester
{
  public static void main (String[] args)
  {
    Card c = new Card(Card.Shape.OVAL, Card.Color.RED, Card.Number.TWO, Card.Fill.SOLID);
    Card c2 = new Card(Card.Shape.OVAL, Card.Color.GREEN, Card.Number.TWO, Card.Fill.SOLID);
    System.out.println(c);
    System.out.println(c2);
    Deck d = new Deck();
    System.out.println(d);
    d.shuffle();
    System.out.println(d);
    BoardSquare bs = new BoardSquare(c,0,1);
    System.out.println(bs.getCard());
    System.out.println(bs.getRow());
    System.out.println(bs.getCol());
    bs.setCard(c2);
    bs.setRow(2);
    bs.setCol(0);
    System.out.println(bs.getCard());
    System.out.println(bs.getRow());
    System.out.println(bs.getCol());
    if (!d.isEmpty())
      System.out.println("hi");
    System.out.println(d.getTopCard());
     Board b = new Board(d);
    System.out.println(b);
  
    System.out.println(b.numCols());
    System.out.println(b.numRows());
    System.out.println(b.getCard(1,1));
    b.add3(d);
   
   
    System.out.println(b);
    b.add3(d);
   
    System.out.println(b);
    b.replaceCard(c,2,0);
    System.out.println(b);
    BoardSquare bs2 = b.getBoardSquare(2,3);
    System.out.println(bs2.getRow());
    System.out.println(bs2.getCol());
    System.out.println(b.getCard(2,2));
    System.out.println(b.numRows());
    System.out.println(b.numCols());
    
    BoardSquare bs3 = b.getBoardSquare(0,2);
    System.out.println(bs3.getRow());
    System.out.println(bs3.getCol());
    b.replaceCard(c,1,1);
    System.out.println(b.getCard(0,0));
    System.out.println(b);
    if (Card.isSet(b.getCard(0,0), b.getCard(0,1), b.getCard(0,2)))
      System.out.println("1. set");
    if (Card.isSet(b.getCard(1,0), b.getCard(1,1), b.getCard(1,2)))
      System.out.println("2. set");
    if (Card.isSet(b.getCard(2,0), b.getCard(2,1), b.getCard(2,2)))
      System.out.println("3. set");
    if (Card.isSet(b.getCard(0,0), b.getCard(1,0), b.getCard(2,0)))
      System.out.println("col 1. set");
    if (Card.isSet(b.getCard(0,1), b.getCard(1,1), b.getCard(2,1)))
      System.out.println("col 2. set");
    if (Card.isSet(b.getCard(0,2), b.getCard(1,2), b.getCard(2,2)))
      System.out.println("col 3. set");
    if (Card.isSet(b.getCard(0,3), b.getCard(1,3), b.getCard(2,3)))
      System.out.println("col 4. set");
   
  }
}