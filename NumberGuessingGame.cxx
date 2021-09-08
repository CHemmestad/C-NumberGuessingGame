/*
 * Caleb Hemmestad
 * September 7, 2021
 * C++
 * Guessing game
 */

#include <iostream>

using namespace std ; 

// Creating a function so I can change each game mode without having a bunch of lines of code
void playGame ( int numberSize , int max , int lives ) {
	int com ; // com for computer
	int playerGuess = 9999 ;
	long x = 0 ; // Just a generic variable used for counting
	int c = 0 ; // Generic varible used for determining which sentence to output
			
	// Computer is finding a random number to use for guessing
	srand(time(NULL)) ;
	com = rand() %numberSize + 1 ;
	while ( com > max ) {
		srand(time(NULL)) ;
		com = rand() %numberSize + 1 ;
		// The animation for while computer is finding a number
		x++ ;
		if ( x == 1 ) {
			c = 1 ;
		} else if ( x == 1000000 ) {
			c = 3 ;
		} else if ( x == 2000000 ) {
			c = 5 ;
		} else if ( x == 3000000 ) {
			c = 7 ;
		} else if ( x == 4000000 ) {
			x = 0 ;
		}
		if ( c == 1 ) {
			system ( "clear" ) ;
			cout << "\n\t\t\tThinking of a number" << endl ;
			c = 2 ;
		} else if ( c == 3 ) {
			system ( "clear" ) ;
			cout << "\n\t\t\tThinking of a number    ." << endl ;
			c = 4 ;
		} else if ( c == 5 ) { 
			system ( "clear" ) ;
			cout << "\n\t\t\tThinking of a number    .    ." << endl ;
			c = 6 ;
		} else if ( c == 7 ) {
			system ( "clear" ) ;
			cout << "\n\t\t\tThinking of a number    .    .    ." << endl ;
			c = 8 ;
		}
	}
	system ( "clear" ) ;
	cout << "\n\t\t\t\tOK. I'm ready!" << endl ;
	
	// Printing out if the number is too high or too low and seeing if the player won or lost
	while ( lives > 0 ) {
		cout << "\nYou have " ;
		cout << lives ;
		cout << " lives." << endl ;
		cout << "\n\t\t     Pick a number between 0 and " ;
		cout << max ;
		cout << " : " ;
		
		cin >> playerGuess ; // Asking player for their guess
		
		if ( !cin ) {
			cout << "Input error, ending program." << endl ;
			break ;
		}
		
		system ( "clear" ) ;
		if ( playerGuess < 0 || playerGuess > max ) {
			cout << "\nInvalid input! Try again." << endl ;
		} else if ( playerGuess < com ) {
			cout << "\n\t\t\t\t     Wrong!" << endl ;
			lives = lives - 1 ;
			cout << "\t\t      Mystery number is greater than " ;
			cout << playerGuess << endl ;
		} else if ( playerGuess > com ) {
			cout << "\n\t\t\t\t     Wrong!" << endl ;
			lives = lives - 1 ;
			cout << "\t\t       Mystery number is less than " ;
			cout << playerGuess << endl ;
		} else if ( playerGuess == com ) {
			cout << "\n\t\t       Congratulations! You win!" << endl ;
			break ;
		}
	} if ( lives == 0 ) {
		cout << "\n\t\t       You ran out of lives. You lose!" << endl ;
	} if ( playerGuess != com ) {
		cout << "\t\t\t       The number was " ;
		cout << com << endl ;
	}
}
	
int main(int argc, char **argv)
{
	
	system ( "clear" ) ;
		
	char welcomeMessage [9] [81] ;
	char play ;
	// Simple variables for counting and filtering through array
	int v ; // v for vertical
	int h ; // h for horizontal
	// Variables for changing the way it looks
	int s = 9 ; // s for shift because it shifts the word left or right to center it
	char c = 'O' ; // c for character to change the character used to form the letters for the banner
	char e = ' ' ; // e for empty to change the character used to fill in the empty spaces
	char b = 'H' ; // b for border to change the border
	
	// Making welcome banner
	for ( v = 0 ; v < 8 ; v++ ) {
		for ( h = 0 ; h < 80 ; h++) {
			if (( v > 0 && v < 6 ) && ( h == 0+s || h == 4+s || h == 8+s )) { 
				welcomeMessage [ v ] [ h ] = c ;
			} else if (( v == 6 ) && (( h > 0+s && h < 4+s ) || ( h > 4+s && h < 8+s ))) { // Makes the W
				welcomeMessage [ v ] [ h ] = c ;
			} else if ((( v > 0 && v < 7 ) && ( h == 11+s )) || (( v == 1 || v == 6 || v == 4 ) && ( h > 11+s && h < 17+s ))) { // Makes the E
				welcomeMessage [ v ] [ h ] = c ;
			} else if (( v > 0 && v < 7 && h == 19+s ) || ( v == 6 && h > 19+s && h < 25+s )) { // Makes the L
				welcomeMessage [ v ] [ h ] = c ;
			} else if (( v > 1 && v < 6 && h == 27+s ) || (( v == 2 || v == 5 ) && ( h == 33+s )) || (( v == 1 || v == 6 ) && ( h > 27+s && h < 33+s ))) { // Makes the C
				welcomeMessage [ v ] [ h ] = c ;
			} else if ((( v > 1 && v < 6 ) && ( h == 36+s || h == 42+s )) || (( v == 1 || v == 6 ) && ( h > 36+s && h < 42+s ))) { // Makes the O
				welcomeMessage [ v ] [ h ] = c ;
			} else if ((( v > 0 && v < 7 ) && ( h == 45+s || h == 53+s )) || (( v == 2 ) && ( h == 46+s || h == 52+s )) || (( v == 3 ) && // Makes the M
			( h == 47+s || h == 51+s )) || (( v == 4 ) && ( h == 48+s || h == 50+s )) || (( v == 5 ) && ( h == 49+s ))) { 
				welcomeMessage [ v ] [ h ] = c ;
			} else if ((( v > 0 && v < 7 ) && ( h == 56+s )) || (( v == 1 || v == 6 || v == 4 ) && ( h > 56+s && h < 62+s ))) { // Makes the E
				welcomeMessage [ v ] [ h ] = c ;
			} else if ( v == 0 || v == 7 ) {
				welcomeMessage [ v ] [ h ] = b ;
			}
			else {
				welcomeMessage [ v ] [ h ] = e ;
			}
		}
	}
	
	// Displaying banner
	cout << "\n\n\n\n\n\n" ;
	for ( v = 0 ; v < 8 ; v++ ) {
		for ( h = 0 ; h < 80 ; h++) {
			cout << welcomeMessage [ v ] [ h ] ;
		}
		cout << "\n" ;
	}
	
	// Asking to play
	cout << "\n\t This is the number guessing game! Do you want to play? Y/N : " ;
	cin >>  play ;
	
	if ( play == 'Y' || play == 'y') {
	
		Restart :
		
		char difficulty = ' ' ;
		system ( "clear" ) ;
		
		// Difficulty select screen
		DifficultySelect :
		
		cout << "\n\n\n\n\n\n\n\t\t\tSelect a difficulty setting.\n" << endl ;
		cout << "\t\t    'E' Easy: \t\t0 - 5 and 3 lives" << endl ;
		cout << "\t\t    'M' Medium: \t0 - 10 and 3 lives" << endl ;
		cout << "\t\t    'H' Hard: \t\t0 - 50 and 3 lives" << endl ;
		cout << "\t\t    'X' Extreme: \t0 - 100 and 4 lives" << endl ;
		cout << "\t\t    'I' Impossible: \t0 - 1,000 and 5 lives" << endl ;
		
		cin >> difficulty ;
		system ( "clear" ) ;
		
		// Different game modes to choose from using the game mode function
		if (difficulty == 'E' || difficulty == 'e' ) {
			playGame ( 10 , 5 , 3 ) ;
		} else if ( difficulty == 'M' || difficulty == 'm' ) {
			playGame ( 100 , 10 , 3 ) ;
		} else if ( difficulty == 'H' || difficulty == 'h' ) {
			playGame ( 100 , 50 , 3 ) ;
		} else if ( difficulty == 'X' || difficulty == 'x' ) {
			playGame ( 1000 , 100 , 4 ) ;
		} else if ( difficulty == 'I' || difficulty == 'i' ) {
			playGame ( 10000 , 1000 , 5 ) ;
		} else {
			cout << "You're an idiot. Try again." << endl ;
			goto DifficultySelect ;
		}
		
		char yesNo ;
		
		// Asking to play again
		if ( !cin ) {
			goto End ;
		}
		cout << "\n\nDo you want to play again? Y/N" << endl ;
		cin >> yesNo ;
		if ( yesNo == 'Y' || yesNo == 'y' ) {
			system ( "clear" ) ;
			goto Restart ;
		} else if ( yesNo == 'N' || yesNo == 'n' ) {
			cout << "\nYou're missing out but whatever I guess." << endl ;
		} else { 
			cout << "\nYou can't play if you don't know how to read. Ending game." << endl ;
		}
	} else if ( play == 'N' || play == 'n' ) {
		cout << "\nYou're missing out but whatever I guess." << endl ;
	} else { 
		cout << "\nYou can't play if you don't know how to read. Ending game." << endl ;
	}
 	End : 
	return 0;
}

