// This is a C++ remake of a game I created in the summer of 2016 in Python.
#include <iostream>
#include <ctime> //for time()
#include <cstdlib> //for rand() and srand()

using namespace std;

//Function prototypes.
void start(int);
void ladder_room();
void bear_room();
void treasure_room(int);
void question_room();
void astral_plane();

int main()
{
	//int userChoice;

	srand(static_cast<double>(time(NULL)));
	rand();

	int max_value = 6;

	cout << "Welcome to this text based adventure game! " << endl;
	cout << "It is very short, and not very exciting, but it's the first game I have ever made, so enjoy all 3 minutes of it!!" << endl;
	cout << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	start(max_value);



	system("pause");
	return 0;
}

void start(int max_value)
{
	//Set up variables. 
	int userChoice;

	//Start monologue. 
	cout << "You have entered a dark room, the door you came from swings shut and locks behind you." << endl;
	cout << "There are three doors in this room asside from the one you just came from." << endl;
	cout << "Which door will you pick?" << endl;
	cout << "1, 2 or 3?" << endl;
	cin >> userChoice;


	if (userChoice == 1)
	{
		cout << endl;
		cout << "You have chosen the first door. It creaks open revealing the next room....." << endl;
		ladder_room();
	}

	else if (userChoice == 2)
	{
		cout << endl;
		cout << "The second door is your chosen destination. You hear heavy breathing as you walk through." << endl;
		bear_room();
	}

	else if (userChoice == 3)
	{
		cout << endl;
		cout << "The final door is the one you choose. Lets see what it holds." << endl;
		cout << "The door is hard to push open and you have to really bang it. You hear things fall on the other side." << endl;
		treasure_room(max_value);
	}

	else
	{
		cout << endl;
		cout << "You have decided not to choose a door." << endl;
		cout << "The walls start to move in after several hours of you waiting and you are eventually crushed to death." << endl;
	}
}

void ladder_room()
{
	cout << "You walk into dark room with your hands waving in front of you." << endl;
	cout << "You can feel smooth wood and realise there is a ladder in front of you leaning on the wall." << endl;
	cout << "It is too dark to know if the ladder is safe to climb." << endl;
	cout << "What do you want to do? " << endl;

	cout << "1. Feel around the room." << endl;
	cout << "2. Cry and wait for help." << endl;
	cout << "3. Attempt to climb the ladder." << endl;
	cout << "4. Go back out the way you came." << endl;


	int userChoice;
	bool actionChosen = false;


	cin >> userChoice;
	if (userChoice == 1)
	{
		cout << "You find a lantern with what feels like a box of matches " << endl;
		cout << "You light the lantern and can clearly see the ladder and all the broken bits." << endl;
		cout << "You climb up the ladder safley and enter a cave up above." << endl;
		actionChosen = true;
		question_room();
	}


	else if  (userChoice == 2)
	{
		cout << "You hear a whisper in the wind telling you to gather courage and try again." << endl;
		actionChosen = false;
	}

	else if (userChoice == 3)
	{
		cout << "As you start to climb the ladder you don't notice the broken rings." << endl;
		cout << "You fall to your death. You should not have been so foolish." << endl;
		actionChosen = true;
	}
	
	else if (userChoice == 4)
	{
		cout << "As you push open the door you went through you scratch yourself on a poisonous nail." << endl;
		cout << "You slowly die and your body turns to dust." << endl;
		actionChosen = true;
	}
		
	else
	{
		cout << "Please select an option." << endl;
		actionChosen = false;
	}

}

void bear_room()
{
	cout << "As you enter the room you feel warmth being pushed into your face." << endl;
	cout << "You realise there is an enourmous bear in the room, filling it almost entirely and in the way of the door on the other side. " << endl;
	cout << "As you try and walk accross the room to see the door better you stand on a bone and it breaks with a large SNAP." << endl;
	cout << "The bear makes a noise and opens one eye to look at you." << endl;
	cout << "You spin around in a panic and notice a small harp in the corner." << endl;
	cout << "What do you do?" << endl;

	//Perhaps in later games implement a timed question. Die if you run out of time. 



	int userChoice;
	int runAwayFromBear;
	const int arraySize = 3;
	int live[arraySize] = { 2, 4, 6 };
	int die[arraySize] = { 1, 3, 5 };
	bool choiceMade = false;


	cout << "1. Run to the harp and start running your fingers over the strings." << endl;
	cout << "2. Run over to the harp and start plucking the strings." << endl;
	cout << "3. Make a run for the door. " << endl;
	cout << "4. Stand there terrified. THERE IS A BEAR NEXT TO YOU!!" << endl;

	cin >> userChoice;

	if (userChoice == 1)
	{
		cout << "The bears eyes start to close and his breathing gets steady." << endl;
		cout << "You take the harp and walk to the door, brushing your fingers as you go. " << endl;
		cout << "As you open the door, you play a few more cords, place the harp down and slowly close the door behind you." << endl;
		question_room();
	}
	
	else if (userChoice == 2)
	{
		cout << "The bear gets drowsy, now is your chance to get to the door! " << endl;
		cout << "As you run accross the room the bear seems to still be awake." << endl;
		cout << "Select a number between 1 and 6 to see if you live." << endl;

		cin >> runAwayFromBear;

		if (choiceMade == false)
		{
			for (int i = 0; i < arraySize; i++)
			{
				if (runAwayFromBear == live[i])
				{
					cout << "You manage to pluck the strings enough to slow the bear and get to the door." << endl;
					cout << "You open the door and close it behind you with a reassuring click." << endl;
					cout << "You have safely managed to get into the next room." << endl;
					question_room();
					choiceMade = true;
				}

				else if (runAwayFromBear == die[i])
				{
					cout << "Your plucking isn't making the bear tired. " << endl;
					cout << "In fact, it seems to be annoying the bear that you are in capable of playing the harp." << endl;
					cout << "The bear gets hold of you and slowly starts to seperate your limbs from various areas of your body." << endl;
					choiceMade = true;
				}

				else
				{
					cout << "That is not a valid number." << endl;
					choiceMade = false;
				}
			}
		}

		else if (userChoice == 3)
		{
			cout << "The bear catches you without seeming to move. " << endl;
			cout << "You have barely got even a step from where you were." << endl;
			cout << "You register for a split second.... that it is now all over." << endl;
		}

		else if (userChoice == 4)
		{
			cout << "You faint from fear and your life ends." << endl;
			cout << "Maybe it was painless?" << endl;
		}
	}
}

void treasure_room(int max_value)
{
	cout << "As you push open the door you see piles and piles of gold coins!" << endl;
	cout << "In the center of the room is a note on top of a table held down with a dice." << endl;
	cout << "The note reads. " << endl; 
	cout << "Roll this dice, if you get a 4 or more you will pass on to the next room." << endl;
	cout << "Riches beyond your imagination will await you at home!!" << endl;
	cout << "However, roll a 3 or less and death will surely take you." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~ " << endl;
	cout << "What do you choose to do?" << endl;
	cout << "1. Roll the dice and await my fate!" << endl; 
	cout << "2. Run out the way you came, death won't find you there!" << endl;
	cout << "3. Sit and wait, maybe there is another way?" << endl;

	int userChoice;
	cin >> userChoice;

	int dice;
	dice = rand() / (RAND_MAX / max_value + 1);

	if (userChoice == 1)
	{
		cout << "You pick up the dice, your hands shaking a bit as you shake them." << endl;
		cout << "You throw them onto the table." << endl;
		cout << "Dice rolling....." << endl;

		if (dice >= 4)
		{
			cout << "You roll a " << dice << " ." << endl;
			cout << "Well done, you have survived. The gold vanishes from the room and you can see the way out." << endl;
			astral_plane();
		}

		else if (dice <= 3)
		{
			cout << "You have rolled a " << dice << " ." << endl;
			cout << "The gold vanishes from the room and the lights flicker." << endl;
			cout << "You start to shiver and realise the temperature in the room has fallen." << endl;
			cout << "A cold hand takes yours and leads you into darkness." << endl;
		}

		else
		{
			cout << "There seems to be an error with this dice." << endl;
		}
	}

	else if (userChoice == 2)
	{
		cout << "You go to the door you came through and touch the handle." << endl;
		cout << "The temperature in the room plummets and your hand freezes in place." << endl;
		cout << "You feel an ice cold blade go through your neck." << endl;
	}
	
	else if (userChoice == 3)
	{
		cout << "As you sit there and wait, you notice a door on the other side of the room." << endl;
		cout << "What do you want to do?" << endl;
		cout << "1. Climb over the treasure taking a few coins and try the door." << endl;
		cout << "2. Climb over the treasure ignoring the coins and try the door." << endl;
		cout << "3. Why bother? It's only going to be locked anyway." << endl;

		int door;
		cin >> door;

		if (door == 1)
		{
			cout << "The second you put the coins in your pocket the whole room shakes." << endl;
			cout << "The coins shake and tumble. You begin to fall through the treasure." << endl;
			cout << "You slowly get crushed under the weight of the treasure and die." << endl;
		}	

		else if (door == 2)
		{
			cout << "You get through the room avoiding the temptation of the room." << endl;
			cout << "The door opens because you weren't greedy." << endl;
			cout << "As you walk into the darkness you fall..... " << endl << " .....slowly drifting until you no longer exist." << endl;
		}

		else if (door == 3)
		{
			cout << "You eventually waste away wishing you were brave enough to roll the dice. " << endl;
		}

		else
		{
			cout << "You eventually waste away. " << endl;
			cout << "Maybe you should have picked a number." << endl;
		}

	}
}

void question_room()
{

	cout << "You have entered a room with a question box in it." << endl;
	cout << "As you approach the box a small mechanical sound starts and paper comes out." << endl;
	cout << "You pick up the paper, it says:" << endl;
	cout << "Welcome traveler! You have got this far! I now have a question for you!" << endl;
	cout << "Where do you scratch a woozle to make it relax?" << endl;
	cout << "1. It's ears." << endl << "2. It's nose" << endl << "3. It's neck?" << endl;

	int userChoice;
	cin >> userChoice;

	if (userChoice == 1)
	{
		cout << "I am afraid not. Good bye" << endl;
	}

	else if (userChoice == 2)
	{
		cout << "I am afraid not. Good bye" << endl;
	}

	else if (userChoice == 3)
	{
		cout << "You are correct! Pass on brave traveler and be rewarded." << endl;
		astral_plane();
	}

	else
	{
		cout << "What kind of an answer is that?" << endl;
	}
}

void astral_plane()
{
	cout << "\n\nCongratulations! You have reached the end of the game!" << endl;
	cout << "If you went via the treasure room you are rich!" << endl;
	cout << "Otherwise, well, your the same as you where but alive!" << endl;
	cout << "Thank you for playing. You are now condemmed to this room." << endl;
	cout << "Maybe one day someone will find you" << endl;
}
