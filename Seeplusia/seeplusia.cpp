#include "seeplusia.hpp"
#include "mover.hpp"

//Initializing Variables:

int applesLeft = 20, nCrystalsFound = 0; 
string gameState  = "Running"; 

string currentState = "Enchanted Forest";
int crystal_at_Marsh_of_Undead = 0;
int crystal_at_Werewolf_Hill = 0;
int crystal_at_Einstien_Tunnel = 0;
int crystal_at_Swamps_of_Despair = 0; 

void makeMove(string direction){
	
	if (applesLeft <= 0)
	{
		gameState = "Lost";
	}
	else 
	{
		if (direction == "East")
		{ //When Right Arrow is pressed
			if ((currentState == "Marsh of Undead") || (currentState == "Apples Orchard") || (currentState == "Werewolf Hill") || (currentState == "Bridge of Death"))
			{
				applesLeft -= 1; //Invalid Move
			}
			else
			{
				if (applesLeft >= 2) //When moving to states which require 3 apples
				{
					if (currentState == "Elvin Waterfall")
					{
						moveEast();
						currentState = "Werewolf Hill"; 
						applesLeft -= 2;
						if (crystal_at_Werewolf_Hill == 0)
						{
							nCrystalsFound += 1; //Total number of crystals increased.
							crystal_at_Werewolf_Hill += 1; // This acts as a flag/checker to ensure no crystal is obtained twice from this state.
						}
					}
					else if (currentState == "Eisten Tunnel")
					{
						moveEast(); 
						currentState = "Elvin Waterfall";
						applesLeft -= 2;
					}
				}
				if (applesLeft >= 1) //When moving to states which require 1 apples
				{
					if (currentState == "Enchanted Forest")
					{
						moveEast();
						currentState = "Sands of Quick";
						applesLeft -= 1;
						gameState = "Lost"; 
					}
		
					else if (currentState == "Wampire Cove")
					{
						moveEast(); 
						currentState = "Marsh of Undead";
						if (crystal_at_Marsh_of_Undead == 0)
						{
							nCrystalsFound += 1; 
							crystal_at_Marsh_of_Undead += 1;
						}
						applesLeft -= 1;
					}
					else if (currentState == "Swamps of Despair")
					{
						moveEast(); 
						currentState = "Wampire Cove";
						applesLeft -= 1;
					}
				}
			}
		}
		else if (direction == "West")
		{ //When Left Arrow is pressed
			if (currentState == "Enchanted Forest" || currentState == "Swamps of Despair" || currentState == "Eisten Tunnel")
			{
				applesLeft -= 1;
			}
			else
			{
				if (applesLeft >= 5)
				{
					if (currentState == "Bridge of Death")
					{
						if (nCrystalsFound == 4)
						{
							moveWest();
							currentState = "Wizards Castle";
							gameState = "Won";
							applesLeft -= 5;
						}
					}
				}
				if (applesLeft >= 2)
				{	
					if (currentState == "Werewolf Hill")
					{
						moveWest();
						currentState = "Elvin Waterfall";
						applesLeft -= 2;
					}
					else if (currentState == "Elvin Waterfall")
					{
						moveWest();
						currentState = "Eisten Tunnel";
						if (crystal_at_Einstien_Tunnel == 0)
						{
							nCrystalsFound += 1;
							crystal_at_Einstien_Tunnel += 1;
						}
						applesLeft -= 2;
					}
				}
				if (applesLeft >= 1)
				{
					if (currentState == "Wampire Cove")
					{
						moveWest();
						currentState = "Swamps of Despair";
						if (crystal_at_Swamps_of_Despair == 0)
						{
							nCrystalsFound += 1;
							crystal_at_Swamps_of_Despair += 1;
						}
						applesLeft -= 1;
					}
					else if (currentState == "Marsh of Undead")
					{
						moveWest();
						currentState = "Wampire Cove";
						applesLeft -= 1;
					}
					else if (currentState == "Apples Orchard")
					{
						moveWest();
						currentState = "Werewolf Hill";
						if (crystal_at_Werewolf_Hill == 0)
						{
							nCrystalsFound += 1;
							crystal_at_Werewolf_Hill += 1;
						}
						applesLeft -= 1;
					}
				}
			}
		}
		else if (direction == "North")
		{ //When Up Arrow is pressed
			if (currentState == "Bridge of Death" || currentState == "Enchanted Forest" || currentState == "Marsh of Undead" || currentState == "Apples Orchard" || currentState == "Elvin Waterfall")
			{
				applesLeft -= 1;
			}
			else
			{
				if (applesLeft >= 10)
				{
					if (currentState == "Eisten Tunnel" && nCrystalsFound >= 3)
					{
						moveNorth(); 
						moveNorth(); 
						currentState = "Wizards Castle";
						applesLeft -= 10; 
						gameState = "Won";
					}
				}
				if (applesLeft >= 3)
				{
					if (currentState == "Wampire Cove")
					{
						moveNorth();
						currentState = "Enchanted Forest";
						applesLeft -= 3;
					}
					else if (currentState == "Werewolf Hill")
					{
						moveNorth();
						currentState = "Wampire Cove";
						applesLeft -= 3;
					}
				}
				if (applesLeft >= 1)
				{
					if (currentState == "Swamps of Despair")
					{
						moveNorth();
						currentState = "Bridge of Death";
						applesLeft -= 1;
					}
				}
			}
		}
		else if (direction == "South")
		{//When Down Arrow is pressed
			if (currentState == "Bridge of Death" || currentState == "Swamps of Despair" || currentState == "Eisten Tunnel" || currentState == "Elvin Waterfall" || currentState == "Werewolf Hill" || currentState == "Apples Orchard") 
			{
				applesLeft -= 1;
			}
			else
			{
				if (applesLeft >= 3)
				{
					if (currentState == "Enchanted Forest")
					{
						moveSouth();
						currentState = "Wampire Cove";
						applesLeft -= 3;
					}
					else if (currentState == "Wampire Cove")
					{
						moveSouth();
						currentState = "Werewolf Hill";
						applesLeft -= 3;
						if (crystal_at_Werewolf_Hill == 0)
						{
							nCrystalsFound += 1;
							crystal_at_Werewolf_Hill += 1;
						}
					}
				}
				if (applesLeft >= 1)
				{
					if (currentState == "Marsh of Undead")
					{
						moveSouth();
						currentState = "Apples Orchard";
						applesLeft -= 1; 
						applesLeft += 6;
					}
				}
			}
		}
	}
}