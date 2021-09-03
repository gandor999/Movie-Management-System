#include <iostream>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <cstring>

#define max_number_of_movies 10000
using namespace std;


class System
{
	protected:
		
		int number_of_choice;
	
	public:
		
		void create_txt_files_needed()
		{
			
			ifstream check_files("Full List of Movies.txt");
			
			if(! check_files)
			{
				ofstream list1("Full List of Movies.txt");
				ofstream list2("List - Category - Action.txt");
				ofstream list3("List - Category - Adventure.txt");
				ofstream list4("List - Category - Comedy.txt");
				ofstream list5("List - Category - Documentary.txt");
				ofstream list6("List - Category - Drama.txt");
				ofstream list7("List - Category - NSFW.txt");
				ofstream list8("List - Category - Horror.txt");
				
				list1.close();
				list2.close();
				list3.close();
				list4.close();
				list5.close();
				list6.close();
				list7.close();
				list8.close();
							
				ofstream path1("Full Path of Movies.txt");
				ofstream path2("Path - Category - Action.txt");
				ofstream path3("Path - Category - Adventure.txt");
				ofstream path4("Path - Category - Comedy.txt");
				ofstream path5("Path - Category - Documentary.txt");
				ofstream path6("Path - Category - Drama.txt");
				ofstream path7("Path - Category - NSFW.txt");
				ofstream path8("Path - Category - Horror.txt");	
				
				path1.close();
				path2.close();
				path3.close();
				path4.close();
				path5.close();
				path6.close();
				path7.close();
				path8.close();
			}
			
			check_files.close();
			
		}
		
		
		void swap(int *p1, int *p2)
		{
			int temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
	
		void swapnames(string *p1, string *p2)
		{
			string temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
	
		int letterrank(char letter)
		{
			int rank = 0;
			char upperletter[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			char lowerletter[100] = "abcdefghijklmnopqrstuvwxyz";
			
			for(int i = 0; i < strlen(upperletter); ++i)
			{
				if(letter == upperletter[i])
				{
					rank = i + 1;
				}
			}
			
			for(int i = 1; i < strlen(lowerletter); ++i)
			{
				if(letter == lowerletter[i])
				{
					rank = i + 1;
				}
			}
			
			return rank;
			
		}
	
		
		void intro()
		{
			fflush(stdin);
			
			cout << "Movie Management System\n";
			cout << endl;
			
			cout << "Press number to choose:\n\n " << endl;
			
			cout << "1. Pick a Movie\n";
			cout << "2. Add a Movie\n";
			
			
			while(true)
			{
				cin >> number_of_choice;
				
				if(number_of_choice == 1 || number_of_choice == 2)
				{
					break;
				}
			}
			
			cin.ignore();
			
			cout << endl;
			
			system("CLS");
			
			
			if(number_of_choice == 1)
			{
				pick_a_movie();
			}
			
			if(number_of_choice == 2)
			{
				add_movie();
			}	
		}
	
		
		void pick_a_movie()
		{
			fflush(stdin);
			
			cout << "Search by category?\n\n" <<endl;
			
			cout << "1.Yes\n2.No\n\n0 Go Back" << endl;
			
			cin >> number_of_choice;
			
			system("CLS");
			
			if(number_of_choice == 0)
			{
				intro();
			}
			
			if(number_of_choice == 1)
			{
				search_category();                                      
			}
			
			else if(number_of_choice == 2)
			{
				list_of_movies();										// wa pay list of movies funciton na himo  -- himoon ra ni after the add movie funciton is done
			}
		}
		
		
		void add_movie()												// comeback here later since medyo complicated na ni sila na part
		{	
			char movie_path[FILENAME_MAX];
			char movie_title[1000];
			char choice[7];
			
			while(true)
			{
				fflush(stdin);
				
				cout << "Enter Title of Movie\n";
				cin.getline(movie_title, 100);
				
							
				system("CLS");
						
				cout << "Drag and drop movie file here: \n";
				cin.getline(movie_path, FILENAME_MAX);
				
				
				system("CLS");
				
				if(check_in_list(movie_path) == 0)
				{
					break;
				}
				
				if(check_in_list(movie_path) == 1)
				{
					cout << "Movie is already in System\n\n";
					cout << "Press 1 to add different movie or 0 to go back to main menu\n\n";
					
					cin >> number_of_choice;
					
					system("CLS");
					
					if(number_of_choice == 0)
					{
						intro();
					}
				}
			}
			
		

			cout << "What category is this movie?\n\n" << endl;
			cout << "Input numbers that apply ex. 1234 :\n\n" << endl;
			
			cout << "1. Action" << endl;
			cout << "2. Adventure" << endl;
			cout << "3. Comedy" << endl;
			cout << "4. Documentary" << endl;
			cout << "5. Drama" << endl;
			cout << "6. NSFW" << endl;
			cout << "7. Horror" << endl;
			
			cout << "\n\n" << endl;
			cin.getline(choice, 7);
			cout << endl;
			system("CLS");	
			
			cout << "Adding movie...\n\n";
			
			for(int i = 0; i < 7; ++i)
			{
				if(i == 1)   // for some reason mu gana ra ni siya if after na plusan siya ug 1, C++ so weird
				{
					adding_process("Full List of Movies.txt", "Full Path of Movies.txt", movie_title, movie_path);
				}
				
				if(choice[i] == '1')
				{
					adding_process("List - Category - Action.txt", "Path - Category - Action.txt", movie_title, movie_path);
					
				}
				
				if(choice[i] == '2')
				{
					adding_process("List - Category - Adventure.txt", "Path - Category - Adventure.txt", movie_title, movie_path);
				}
				
				if(choice[i] == '3')
				{
					adding_process("List - Category - Comedy.txt", "Path - Category - Comedy.txt", movie_title, movie_path);
				}
				
				if(choice[i] == '4')
				{
					adding_process("List - Category - Documentary.txt", "Path - Category - Documentary.txt", movie_title, movie_path);
				}
				
				if(choice[i] == '5')
				{
					adding_process("List - Category - Drama.txt", "Path - Category - Drama.txt", movie_title, movie_path);
				}
				
				if(choice[i] == '6')
				{
					adding_process("List - Category - NSFW.txt", "Path - Category - NSFW.txt", movie_title, movie_path);
				}
				
				if(choice[i] == '7')
				{
					adding_process("List - Category - Horror.txt", "Path - Category - Horror.txt", movie_title, movie_path);
				}
			}
			
			cout << "Successfully added movie!\n\n";
			
			cout << "1. Add another movie\n2. Main Menu\n";
			cin >> number_of_choice;
			
			system("CLS");
			
			if(number_of_choice == 1)
			{
				add_movie();
			}
			
			if(number_of_choice == 2)
			{
				intro();
			}						
		}
		
		
		void search_category()											// please add other categories after add movie funciton is made
		{
			
			fflush(stdin);
			
			cout << "Pick a Category:\n\n " << endl;
			
			cout << "1. Action" << endl;
			cout << "2. Adventure" << endl;
			cout << "3. Comedy" << endl;
			cout << "4. Documentary" << endl;
			cout << "5. Drama" << endl;
			cout << "6. NSFW" << endl;
			cout << "7. Horror\n\n0 Go Back" << endl;
			
			cout << endl;
			
			cin >> number_of_choice;
			
			system("CLS");
			
			if(number_of_choice == 0)
			{
				pick_a_movie();
			}
			
			cout << "\n\n\n";
			
			if(number_of_choice == 1)  
			{
				play_movie("List - Category - Action.txt", "Path - Category - Action.txt");
			}
			
			if(number_of_choice == 2)
			{
				play_movie("List - Category - Adventure.txt", "Path - Category - Adventure.txt");
			}
			
			if(number_of_choice == 3)
			{
				play_movie("List - Category - Comedy.txt", "Path - Category - Comedy.txt");
			}
			
			if(number_of_choice == 4)
			{
				play_movie("List - Category - Documentary.txt", "Path - Category - Documentary.txt");
			}
			
			if(number_of_choice == 5)
			{
				play_movie("List - Category - Drama.txt", "Path - Category - Drama.txt");
			}
			
			if(number_of_choice == 6)
			{
				play_movie("List - Category - NSFW.txt", "Path - Category - NSFW.txt");
			}
			
			if(number_of_choice == 7)
			{
				play_movie("List - Category - Horror.txt", "Path - Category - Horror.txt");
			}
			
			
		}
		
		
		void list_of_movies()
		{
			fflush(stdin);
			
			string list_of_movies[max_number_of_movies];
			string path_of_movies[max_number_of_movies];
			char movie_name[1000];
			char path_name[1000];
			
			ifstream action_list("Full List of Movies.txt");
			ifstream action_path("Full Path of Movies.txt");
			
			for(int i = 0; i < max_number_of_movies; ++i)
			{
				action_list.getline(movie_name, 1000);        // iya e convert ang lines sa file txt into a temporary array
				list_of_movies[i] = movie_name;
				
				action_path.getline(path_name, 1000);        // iya e convert ang lines sa file txt into a temporary array
				path_of_movies[i] = path_name;
			}
			
			action_list.close();
			action_path.close();
			
			for(int i = 0; i < max_number_of_movies; ++i)
			{
				if(list_of_movies[i] != "")
				{
					cout << i + 1 << ". " << list_of_movies[i] << endl;
				}
			}
			
			
			cout << "\n\nPick a movie to play or Press 0 to go back: ";
			cin >> number_of_choice;
			
			if(number_of_choice == 0)
			{
				pick_a_movie();
			}
			
			system("CLS");
			cout << endl;
			cout << "Enjoy the Movie!";
			cout << endl;
			
			char movie[1000];
			
			for(int i =  0; i < path_of_movies[number_of_choice - 1].size(); ++i)
			{
				movie[i] = path_of_movies[number_of_choice - 1][i];
			}

			system(movie);
		}
		
		void adding_process(string list_filename, string path_filename, char movie_title[1000], char movie_path[1000])
		{
			string list_of_movies[10000];
			string path_of_movies[10000];
			char movie_name[1000];
			char path_name[FILENAME_MAX];
			
			int namerank[1000];
			int secondletterrank[1000];
			int thirdletterrank[1000];
			
			// stream handling starts here
					
			ofstream add_to_list;    
			ofstream add_to_path;
			
			add_to_list.open(list_filename, ios_base::app);
			add_to_list << movie_title;
			
			add_to_path.open(path_filename, ios_base::app);
			add_to_path << movie_path;
			
			add_to_list.close();
			add_to_path.close();
			
			ifstream action_list(list_filename);
			ifstream action_path(path_filename);
			
			for(int i = 0; i < 1000; ++i)
			{
				action_list.getline(movie_name, 1000);        // iya e convert ang lines sa file txt into a temporary array
				list_of_movies[i] = movie_name;
				
				action_path.getline(path_name, FILENAME_MAX);        // iya e convert ang lines sa file txt into a temporary array
				path_of_movies[i] = path_name;
									
			}
			
			action_list.close();
			action_path.close();
			
			// the sorter seems to be working fine
			
			for(int i = 0; i < 1000; ++i)
			{
				namerank[i] = letterrank(list_of_movies[i][0]);
				secondletterrank[i] = letterrank(list_of_movies[i][1]);
				thirdletterrank[i] = letterrank(list_of_movies[i][2]);
			}	
			
			for(int i = 0; i < 4; ++i)
			{
				for(int j = i + 1; j < 4; ++j)
				{
					if(namerank[i] > namerank[j])
					{
						swap(&namerank[i], &namerank[j]);
						swap(&secondletterrank[i], &secondletterrank[j]);
						swapnames(&list_of_movies[i], &list_of_movies[j]);
						swapnames(&path_of_movies[i], &path_of_movies[j]);
					}
					
					else if(namerank[i] == namerank[j] && secondletterrank[i] > secondletterrank[j])
					{
						swap(&secondletterrank[i], &secondletterrank[j]);
						swap(&namerank[i], &namerank[j]);
						swapnames(&list_of_movies[i], &list_of_movies[j]);
						swapnames(&path_of_movies[i], &path_of_movies[j]);
					}
					
					else if(namerank[i] == namerank[j] && secondletterrank[i] == secondletterrank[j] && thirdletterrank[i] > thirdletterrank[j])
					{
						swap(&thirdletterrank[i], &thirdletterrank[j]);
						swap(&secondletterrank[i], &secondletterrank[j]);
						swap(&namerank[i], &namerank[j]);
						swapnames(&list_of_movies[i], &list_of_movies[j]);
						swapnames(&path_of_movies[i], &path_of_movies[j]);
					}
					
				}
			}
			
			// sorter ends here
			
			ofstream replace_list(list_filename);
			ofstream replace_path(path_filename);
			
			for(int i = 0; i < 1000; ++i)
			{
				if(list_of_movies[i] != "")
				{
					replace_list << list_of_movies[i] << "\n";
				}
				
			}
			
			for(int i = 0; i < 1000; ++i)
			{
				if(path_of_movies[i] != "")
				{
					replace_path << path_of_movies[i] << "\n";
				}
			}
			
			replace_list.close();
			replace_path.close();
			
			// stream handling ends here
			
			// Adding ends here
			
		}
		
		void play_movie(string list_filename, string path_filename)
		{
			fflush(stdin);
			
			string list_of_movies[max_number_of_movies];
			string path_of_movies[max_number_of_movies];
			char movie_name[1000];
			char path_name[1000];
			
			ifstream action_list(list_filename);
			ifstream action_path(path_filename);
			
			for(int i = 0; i < max_number_of_movies; ++i)
			{
				action_list.getline(movie_name, 1000);        // iya e convert ang lines sa file txt into a temporary array
				list_of_movies[i] = movie_name;
				
				action_path.getline(path_name, 1000);        // iya e convert ang lines sa file txt into a temporary array
				path_of_movies[i] = path_name;
			}
			
			action_list.close();
			action_path.close();
			
			for(int i = 0; i < max_number_of_movies; ++i)
			{
				if(list_of_movies[i] != "")
				{
					cout << i + 1 << ". " << list_of_movies[i] << endl;
				}
			}
			
			cout << "\n\nPick a movie to play or Press 0 to go back: ";
			cin >> number_of_choice;
			system("CLS");
			
			if(number_of_choice == 0)
			{
				search_category();
			}
			
			cout << endl;
			cout << "Enjoy the Movie!";
			cout << endl;
			
			char movie[1000];
			
			for(int i =  0; i < path_of_movies[number_of_choice - 1].size(); ++i)
			{
				movie[i] = path_of_movies[number_of_choice - 1][i];
			}
		
			system(movie);
			
		}
		
		bool check_in_list(string path_of_movie)
		{
			bool status = false;
			
			string list_of_movies[max_number_of_movies];
			string path_of_movies[max_number_of_movies];
			char movie_name[1000];
			char path_name[1000];
			
			ifstream action_list("Full List of Movies.txt");
			ifstream action_path("Full Path of Movies.txt");
			
			for(int i = 0; i < max_number_of_movies; ++i)
			{
				action_list.getline(movie_name, 1000);        // iya e convert ang lines sa file txt into a temporary array
				list_of_movies[i] = movie_name;
				
				action_path.getline(path_name, 1000);        // iya e convert ang lines sa file txt into a temporary array
				path_of_movies[i] = path_name;
			}
			
			action_list.close();
			action_path.close();
			
			for(int i = 0; i < max_number_of_movies; ++i)
			{
				if(path_of_movie == path_of_movies[i])
				{
					status = true;
				}
			}
			
			return status;
			
		}
		
		
};



int main()
{
	System test;
	
	test.create_txt_files_needed();
	
	test.intro();
	
	system("pause");
	
	return 0;
}

