#include<bits/stdc++.h>
#include<conio.h>
#include<string.h>
#include<sstream>
#include<cstdlib>
#include<string>
#define AROWS 60
#define ATYPES 10

using namespace std;

vector <int> rowList;

class rows
{
	friend class flight;

private:

    string rowNumber;
    string classType;
    string seats;

};

class flight
{

private:
    string flightNumber;
    string dateTime;
    string departureAirport;
    string arrivalAirport;
    rows availableSeats[AROWS];

public:

	void openFile();
	void seatsAvailable();
	void displayFlights();
	void viewFlight();
	void seatBooking();
	void exit();
};

vector<flight> fList;

void flight::seatsAvailable()
{
	cout << "---------------------------------------------------------------------------" << endl;
	string flightNumber;
	string numberOfSeats;
	cout << "\n\t\t---Seat Availability---\n" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "Enter The Flight Number       : ";
	cin >> flightNumber;
	int e,a=0,count=0;
	bool hasLetter=false;
	for(e=0;e<fList.size();e++)
		if(fList[e].flightNumber==flightNumber)
		{
			a=1;
			break;
		}

	if(a==1)
	{
		for(int b=0;b<rowList[e];b++)
		{
			count=count+fList[e].availableSeats[b].seats.length();
		}
		cout << "Number Of Seats That You Need : ";
		cin >> numberOfSeats;

			stringstream geek(numberOfSeats);
  	  		int x = 0;
    		geek >> x;

    	int flag=0;
    	for(int p=0;p<numberOfSeats.size();p++)
    		if(isalpha(numberOfSeats[p]))
    			flag=1;

		if(flag!=1)
		{
			if(count>=x)
			{
				cout << "---------------------------------------------------------------------------" << endl;
				cout << "Yes..Requested Number Of Seats Are Available In The Flight " << flightNumber << endl;
				cout << "---------------------------------------------------------------------------" << endl;
				cout << "\tFlight Number         : " << fList[e].flightNumber <<endl;
				cout << "\tDeparture Date & Time : " << fList[e].dateTime << endl;
				cout << "\tDeparture Airport     : " << fList[e].departureAirport << endl;
				cout << "\tArrival Airport       : " << fList[e].arrivalAirport << endl;
				cout << "\n\tRow Number | Class Type | Free Seats" << endl;
				cout << "\t------------------------------------" << endl;

				for(int g=0;g<rowList[e];g++)
					if(!fList[e].availableSeats[g].seats.empty())
					{
						if(fList[e].availableSeats[g].rowNumber.length()==2)
							cout << "\t    " << fList[e].availableSeats[g].rowNumber << "     |      " << fList[e].availableSeats[g].classType << "     | " << fList[e].availableSeats[g].seats << endl;
						else if(fList[e].availableSeats[g].rowNumber.length()==1)
							cout << "\t    " << fList[e].availableSeats[g].rowNumber << "      |      " << fList[e].availableSeats[g].classType << "     | " << fList[e].availableSeats[g].seats << endl;
					}
			}
			else
			{
				cout << "---------------------------------------------------------------------------" << endl;
				cout << "Sorry..Requested Number Of Seats Are Not Available." << endl;
			}
		}
		else
		{
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "Invalid Input" << endl;
		}

	}
	else
	{
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Sorry..The Flight You Looked For Is Not Available." << endl;
	}
}

void flight::displayFlights()
{
	string type;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\n\t\t---Available Flights---\n" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	int k,m,count1=0,count2=0;

	for(k=0;k<fList.size();k++)
	{
		count1=0,count2=0;
		for(int g=0;g<rowList[k];g++)
		{
			if(fList[k].availableSeats[g].seats.length()!=0)
				count1++;break;
		}
		if(count1>0)
		{
			cout << "\tFlight Number         : " << fList[k].flightNumber <<endl;
			cout << "\tDeparture Date & Time : " << fList[k].dateTime << endl;
			cout << "\tDeparture Airport     : " << fList[k].departureAirport << endl;
			cout << "\tArrival Airport       : " << fList[k].arrivalAirport << endl;
			cout << "\n\tClass Type | Number Of Free Seats\n";
			cout << "\t---------------------------------" << endl;

			type=fList[k].availableSeats[0].classType;

			for(int i=0;i<rowList[k];i++)
			{
				if(fList[k].availableSeats[i].classType==type)
				{
					count2=count2+fList[k].availableSeats[i].seats.length();
				}
				else
				{
					cout << "\t     " << type << "     |         " << count2 << endl;
					type=fList[k].availableSeats[i].classType;
					count2=fList[k].availableSeats[i].seats.length();
				}
			}
			cout << "\t     " << type << "     |         " << count2 << endl;

				cout << "\n\tRow Number | Class Type | Free Seats" << endl;
				cout << "\t------------------------------------" << endl;

				for(int g=0;g<rowList[k];g++)
					if(!fList[k].availableSeats[g].seats.empty())
					{
						if(fList[k].availableSeats[g].rowNumber.length()==2)
							cout << "\t     " << fList[k].availableSeats[g].rowNumber << "    |     " << fList[k].availableSeats[g].classType << "      |    " << fList[k].availableSeats[g].seats << endl;
						else if(fList[k].availableSeats[g].rowNumber.length()==1)
							cout << "\t     " << fList[k].availableSeats[g].rowNumber << "     |     " << fList[k].availableSeats[g].classType << "      |    " << fList[k].availableSeats[g].seats << endl;
					}
			cout << "---------------------------------------------------------------------------" << endl;

		}
			cout << endl;
	}
}

void flight::viewFlight()
{
	string flightNumber,type;
	int count=0,j=0,k=0,x;
	vector <string> classTypes;
	vector <int> seats;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\n\t\t---View Flights---\n" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "Enter The Flight Number       : ";
	cin >> flightNumber;

	int e,a=0;
	for(e=0;e<fList.size();e++)
		if(fList[e].flightNumber==flightNumber)
		{
			a=1;
			break;
		}

	if(a==1)
	{
		type=fList[e].availableSeats[0].classType;
		classTypes.push_back(type);
		k++;

		for(int i=0;i<rowList[e];i++)
			if(fList[e].availableSeats[i].classType==type)
				count=count+fList[e].availableSeats[i].seats.length();
			else
			{
				seats.push_back(count);
				j++;
				classTypes.push_back(fList[e].availableSeats[i].classType);
				k++;
				type=fList[e].availableSeats[i].classType;
				count=fList[e].availableSeats[i].seats.length();
			}
		seats.push_back(count);

		cout << "---------------------------------------------------------------------------" << endl;
		cout << "\tFlight Number         : " << fList[e].flightNumber <<endl;
		cout << "\tDeparture Date & Time : " << fList[e].dateTime << endl;
		cout << "\tDeparture Airport     : " << fList[e].departureAirport << endl;
		cout << "\tArrival Airport       : " << fList[e].arrivalAirport << endl;
		cout << "\n\tClass Type | Number Of Free Seats\n";
		cout << "\t---------------------------------" << endl;

		for(int p=0;p<j+1;p++)
			cout << "\t     "<< classTypes[p] << "     |          " << seats[p] << endl;

				cout << "\n\tRow Number | Class Type | Free Seats" << endl;
				cout << "\t------------------------------------" << endl;

				for(int g=0;g<rowList[e];g++)
					if(!fList[e].availableSeats[g].seats.empty())
					{
						if(fList[e].availableSeats[g].rowNumber.length()==2)
							cout << "\t   " << fList[e].availableSeats[g].rowNumber << "      |      " << fList[e].availableSeats[g].classType << "     |    " << fList[e].availableSeats[g].seats << endl;
						else if(fList[e].availableSeats[g].rowNumber.length()==1)
							cout << "\t   " << fList[e].availableSeats[g].rowNumber << "       |      " << fList[e].availableSeats[g].classType << "     |    " << fList[e].availableSeats[g].seats << endl;
					}
		cout << endl;
	}
	else
	{
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Sorry..The Flight You Looked For Is Not Available." << endl;
	}
}

void flight::seatBooking()
{
	string flightNumb,row;
	char seat;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\n\t\t---Seat Booking---\n" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "Enter The Flight Number       : ";
	cin >> flightNumb;

	int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,e,w,y;

while(flag4!=1)
{
	for(e=0;e<fList.size();e++)
	{
		if(fList[e].flightNumber==flightNumb)
		{
			flag1=1;
			cout << "Row Number Of The Seat        : ";
			cin >> row;

			int flag=0;
    		for(int p=0;p<row.size();p++)
    			if(isalpha(row[p]))
    				flag=1;

    		if(flag!=1)
    		{
				stringstream geek(row);
  	  			int x = 0;
    			geek >> x;


    			if(x>0 && x<=60)
    			{
					for(w=0;w<rowList[e];w++)
					{
						if(fList[e].availableSeats[w].rowNumber==row)
						{
							flag2=1;
							if(fList[e].availableSeats[w].seats.length()!=0)
							{
								flag5=1;
								cout << "Seat Identifier Of The Seat   : ";
								cin >> seat;

								if(seat<='F' && seat>='A')
								{
									int totSeats=fList[e].availableSeats[w].seats.length();
									for(y=0;y<totSeats;y++)
									{
										if(fList[e].availableSeats[w].seats[y]==seat)
										{
											flag3=1;
											fList[e].availableSeats[w].seats.erase(y,1);
											flag4=1;
											cout << "---------------------------------------------------------------------------" << endl;
											cout << "The Seat That You Requested Was Booked For You.";
										}
									}

									if(flag3==0)
									{
										flag4=1;
										cout << "---------------------------------------------------------------------------" << endl;
										cout << "Sorry..Requested Seat Is Already Booked.";
									}
								}
								else
								{
									flag4=1;
									cout << "---------------------------------------------------------------------------" << endl;
									cout << "Seat Identifier That You Enterd Is Not Valid.";
								}
							}

							if(flag5==0)
							{
								flag4=1;
								cout << "---------------------------------------------------------------------------" << endl;
								cout << "Sorry..Requested Row Is Already Booked.";
							}
						}
					}

					if(flag2==0)
					{
						flag4=1;
						cout << "---------------------------------------------------------------------------" << endl;
						cout << "Sorry..Requested Row Is Already Full.";
					}
				}
				else
				{
					flag4=1;
					cout << "---------------------------------------------------------------------------" << endl;
					cout << "Row Number That You Entered Is Not Valid.";
				}
			}
			else
			{
				flag4=1;
				cout << "---------------------------------------------------------------------------" << endl;
				cout << "Row Number That You Entered Is Not Valid.";
			}
		}
	}

	if(flag1==0)
	{
		flag4=1;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Soory..The Flight You Looked For Is Not Available.";
	}
}
	cout << endl;
}


void flight::exit()
{
	ofstream file;
	file.open("flights.txt", ofstream::out | ofstream::trunc);

	for(int i=0;i<fList.size();i++)
	{
		file << fList[i].flightNumber << endl;
		file << fList[i].dateTime << endl;
		file << fList[i].departureAirport << endl;
		file << fList[i].arrivalAirport << endl;

		for(int j=0;j<rowList[i];j++)
		{
			if(!fList[i].availableSeats[j].seats.empty())
			{
				file << fList[i].availableSeats[j].rowNumber << " " << fList[i].availableSeats[j].classType << " " << fList[i].availableSeats[j].seats << endl;
			}
			else
				continue;
		}
		file << endl;
	}

	file.close();

	cout << "---------------------------------------------------------------------------" << endl;
	cout << "\n\t---Thank You For Using Our Service---\n" << endl;
}

void flight::openFile()
{
    fstream file;
	file.open("flights.txt");
	string line;
	int i=0,j=0,c=0,flag=0;

	while(getline(file,line))
    {
    	if(!line.empty())
    	{
    		if(i==0)
    		{
    			fList.push_back(*(new flight));
    			fList[j].flightNumber=line;
    			i++;
    			flag=0;
			}
    		else if(i==1)
    		{
    			fList[j].dateTime=line;
    			i++;
    		}
    		else if(i==2)
    		{
    			fList[j].departureAirport=line;
    			i++;
    		}
    		else if(i==3)
    		{
    			fList[j].arrivalAirport=line;
    			i++;
    		}
    		else
    		{

    			istringstream ss(line);
    			ss >> fList[j].availableSeats[c].rowNumber >> fList[j].availableSeats[c].classType >> fList[j].availableSeats[c].seats;
    			c++;
    		}
		}
		else
		{
			i=0;
			rowList.push_back(c);
			c=0;
			j++;
			flag++;

			if(flag>=2)
			{
				break;
			}
		}
	}
	rowList[j]=c;
}

int main()
{
	flight masterObtect;
    masterObtect.openFile();

    if(!fList.empty())
    {
    	string ch;
    	while(ch!="5")
    	{
    		cout << "---------------------------------------------------------------------------" << endl;
    		cout << "\n\t\t---Welcome To The Virgin Airlines---\n\n";
    		cout << "---------------------------------------------------------------------------" << endl;
    		cout << "\t1. Available Flights\n\t2. View A Flight\n\t3. View Available Seats\n\t4. Book A Seat\n\t5. Exit" << endl;
    		cout << "\nEnter Your Choice             : ";
    		cin >> ch;

    		stringstream geek(ch);

  	  		int x = 0;
    		geek >> x;

    		switch(x)
    		{
    			case 1 : masterObtect.displayFlights();break;
				case 2 : masterObtect.viewFlight();break;
				case 3 : masterObtect.seatsAvailable();break;
				case 4 : masterObtect.seatBooking();break;
				case 5 : masterObtect.exit();break;
				default:{
							cout << "---------------------------------------------------------------------------" << endl;
							cout << "Sorry..Enter A Valid Process." << endl;
							break;
						}
			}
		}
	}
	else
	{
		cout << "Sorry..There Are No Flight That Have Free Seats\n" << endl;
	}

    return 0;
}
