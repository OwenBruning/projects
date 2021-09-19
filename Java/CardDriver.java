import java.util.Scanner; //This is required for the Scanner.
/**
The CardDriver class is the driver for the Card class.
*/
public class CardDriver
{
  public static void main (String[] args)
  {
    String firstCardRank = ""; //These are initialized in order to prevent compiler errors.
    String firstCardSuit = "";
    String secondCardRank = "";
    String secondCardSuit = "";
    Scanner input = new Scanner(System.in); //Create an object called input.
    
    System.out.println("Suit Options List:"); //Display a list containing the suit options.
    System.out.println("1. spades");
    System.out.println("2. clubs");
    System.out.println("3. hearts");
    System.out.println("4. diamonds");
    System.out.print("Enter the suit of the first card (enter 1,2,3, or 4): "); //Prompt the user for the suit of the first card.
    int userSuit = input.nextInt(); //Obtain the suit of the first card.
    System.out.println(); //This line is used for formatting.
    System.out.println("Rank Options List:"); //Display a list containing the rank options.
    System.out.println("1. ace");
    System.out.println("2-10. cards 2 through 10");
    System.out.println("11. jack");
    System.out.println("12. queen");
    System.out.println("13. king");
    System.out.print("Enter the rank of the first card (enter an integer from 1 through 13): "); //Prompt the user for the rank of the first card.
    int userRank = input.nextInt(); //Obtain the rank of the first card.
    Card firstCard = new Card(userSuit,userRank); //Create an object called firstCard.
    System.out.println(); 
    System.out.println("Suit Options List:"); //Display a list containing the suit options.
    System.out.println("1. spades");
    System.out.println("2. clubs");
    System.out.println("3. hearts");
    System.out.println("4. diamonds");
    System.out.print("Enter the suit of the second card (enter 1,2,3, or 4): "); //Prompt the user for the suit of the second card.
    int secondUserSuit = input.nextInt(); //Obtain the suit of the second card.
    System.out.println(); 
    System.out.println("Rank Options List:"); //Display a list containing the rank options.
    System.out.println("1. ace");
    System.out.println("2-10. cards 2 through 10");
    System.out.println("11. jack");
    System.out.println("12. queen");
    System.out.println("13. king");
    System.out.print("Enter the rank of the second card (enter an integer from 1 through 13): "); //Prompt the user for the rank of the second card.
    int secondUserRank = input.nextInt(); //Obtain the rank of the second card.
    System.out.println();
    Card secondCard = new Card(secondUserSuit,secondUserRank); //Create an object called secondCard.
    if (firstCard.getRank() == 1) //Determine the value of firstCardRank by using the getRank method to obtain the rank.
      firstCardRank = "ace";
    else if (firstCard.getRank() == 11) 
      firstCardRank = "jack";
    else if (firstCard.getRank() == 12) 
      firstCardRank = "queen";
    else if (firstCard.getRank() == 13) 
      firstCardRank = "king";
    if (firstCard.getRank() == 1 || firstCard.getRank() == 11 || firstCard.getRank() == 12 || firstCard.getRank() == 13)
      System.out.println("The rank of the first card is: " + firstCardRank + "."); //Display the rank of the first card.
    else
      System.out.println("The rank of the first card is: " + firstCard.getRank() + ".");
 
    if (firstCard.getSuit() == 1) //Determine the value of firstCardSuit by using the getSuit method.
      firstCardSuit = "spades";
    else if (firstCard.getSuit() == 2) 
      firstCardSuit = "clubs";
    else if (firstCard.getSuit() == 3) 
      firstCardSuit = "hearts";
    else if (firstCard.getSuit() == 4) 
      firstCardSuit = "diamonds";
    System.out.println("The suit of the first card is: " + firstCardSuit + "."); //Display the suit of the first card.
    System.out.println("Thus, the first card is: " + firstCard + "."); //This line is used to show the implicit call of the toString method.
    if (secondCard.getRank() == 1) //Determine the value of secondCardRank by using the getRank method.
      secondCardRank = "ace";
    else if (secondCard.getRank() == 11) 
      secondCardRank = "jack";
    else if (secondCard.getRank() == 12) 
      secondCardRank = "queen";
    else if (secondCard.getRank() == 13) 
      secondCardRank = "king";
    if (secondCard.getRank() == 1 || secondCard.getRank() == 11 || secondCard.getRank() == 12 || secondCard.getRank() == 13)
      System.out.println("The rank of the second card is: " + secondCardRank + "."); //Display the rank of the second card.
    else
      System.out.println("The rank of the second card is: " + secondCard.getRank() + ".");
 
    if (secondCard.getSuit() == 1) //Determine the value of secondCardSuit by using the getSuit method.
      secondCardSuit = "spades";
    else if (secondCard.getSuit() == 2) 
      secondCardSuit = "clubs";
    else if (secondCard.getSuit() == 3) 
      secondCardSuit = "hearts";
    else if (secondCard.getSuit() == 4) 
      secondCardSuit = "diamonds";
    System.out.println("The suit of the second card is: " + secondCardSuit + "."); //Display the suit of the second card.
    System.out.println("Thus, the second card is: " + secondCard + "."); //This line is used to show the implicit call of the toString method.
    
    if (firstCard.equals(secondCard)) //Determine whether or not the cards are equal, which is determined by comparing their ranks.
      System.out.println("The cards are the same, since they have the same rank.");
    else
      System.out.println("The cards are different, since they have different ranks.");
  }
}