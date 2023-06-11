#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty)
{
 // Print welcome messages to the terminal
 std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
 std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}
bool PlayGame(int Difficulty)
{
 PrintIntroduction(Difficulty);
 // Declare 3 number code

 const int CodeA{rand() % Difficulty + Difficulty};
 const int CodeB{rand() % Difficulty + Difficulty};
 const int CodeC{rand() % Difficulty + Difficulty};

 const int CodeSum{CodeA + CodeB + CodeC};
 const int CodeProduct{CodeA * CodeB * CodeC};

 // Print sum and product to the terminal
 std::cout << "There are 3 numbers in the code"
           << "\n";
 std::cout << "The sum is :" << CodeSum << "\n";
 std::cout << "The product is : " << CodeProduct << "\n";

 int GuessA, GuessB, GuessC;

 std::cout << "Please enter the first code: ";
 std::cin >> GuessA;

 std::cout << "Please enter the second code: ";
 std::cin >> GuessB;

 std::cout << "Please enter the third code: ";
 std::cin >> GuessC;

 std::cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << "\n";

 int GuessSum{GuessA + GuessB + GuessC};
 int GuessProduct{GuessA * GuessB * GuessC};

 if (GuessSum == CodeSum && GuessProduct == CodeProduct)
 {
  std::cout << "You win!";
  return true;
 }
 else
 {
  std::cout << "You lose!";
  return false;
 }
}

int main()
{

 srand(time(NULL));

 int LevelDifficulty{1};

 while (LevelDifficulty <= 10)
 {
  bool bLevelComplete = PlayGame(LevelDifficulty);
  std::cin.clear();  // Clears any errors
  std::cin.ignore(); // Discards the buffer

  if (bLevelComplete)
  {
   ++LevelDifficulty;

   if (LevelDifficulty > 10)
   {
    std::cout << "You win!";
    break;
   }
  }
 }
 return 0;
}