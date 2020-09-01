#include <iostream>
#include<string>
using namespace std;

class Pool
{
public:
	int RentPool(int numbersHours, int numbPiople)
	{
		return 100 * numbersHours * numbPiople;
	}

	int RentSauna(int numbersHours, int numbPiople)
	{
		return 250 * numbersHours * numbPiople;
	}

};

class Bar
{
public:
	int AlcoholQuality(int alcoholType, int numbPiople)
	{
		switch (alcoholType)
		{
			// beer
		case 1: return 30 * numbPiople;

			// Low-alcohol beverages
		case 2: return 50 * numbPiople;

			//Vodka
		case 3: return 150;

			// No alcohol
		case 4: return 0;

		}
	}

	int DJShow(int numbPiople)
	{
		return 100 * numbPiople;
	}
};

class Restaurant
{
public:
	int Lunch()
	{
		return 250;
	}

	int Dinner()
	{
		return 150;
	}

	int Complex()
	{
		return 550;

	}

};

class Billiard
{
public:
	int RentBilliard(int numbersHours, int numbersTable)
	{
		return 60 * numbersHours * numbersTable;
	}

};

class Massage
{
public:
	int MassageSession(int numbPiople)
	{
		 return 200 * numbPiople;
	}
};

class Hotel
{
public:
	int BookRoom(int roomQuality, int numbersRooms)
	{
		switch (roomQuality)
		{
		case 2:
			return 250 * numbersRooms;
		case 3:
			return 500 * numbersRooms;
		case 4:
			return 900 * numbersRooms;
		default:
			throw new exception("roomQuality should be in range [2;4]");
		}
	}
};

class ObarivResortFasad
{
private:
	Pool _pool;
	Bar _bar;
	Restaurant _restaurant;
	Billiard _billiard;
	Massage _massage;
	Hotel _hotel;
public:
	int One_hour_pleasure_Pool(int numbersHours, int numbPiople, int alcoholType)
	{
		int poolPrice = _pool.RentPool(numbersHours, numbPiople);
		int barPrice = _bar.AlcoholQuality(alcoholType, numbPiople);
		return poolPrice  + barPrice;
	}

	int One_hour_pleasure_Pool_Sauna(int numbersHours, int numbPiople, int alcoholType)
	{
		int poolPrice = _pool.RentSauna(numbersHours, numbPiople);
		int barPrice = _bar.AlcoholQuality(alcoholType, numbPiople);
		return poolPrice + barPrice;
	}

	int One_hour_pleasure_Billiard(int numbersHours, int numbPiople, int alcoholType, int numbersTable)
	{
		int billiardPrice = _billiard.RentBilliard(numbersHours, numbersTable);
		int barPrice = _bar.AlcoholQuality(alcoholType, numbPiople);
		return billiardPrice + barPrice;
	}

	int One_hour_pleasure_Massage(int numbPiople, int alcoholType)
	{
		int massagePrice = _massage.MassageSession(numbPiople);
		int barPrice = _bar.AlcoholQuality(alcoholType, numbPiople);
		return massagePrice + barPrice;
	}

	int One_evening_pleasure(int numbPiople, int alcoholType)
	{
		int restaurantPrice = _restaurant.Dinner();
		int barPrice = _bar.AlcoholQuality(alcoholType, numbPiople);
		int djPricee = _bar.DJShow(numbPiople);
		return (restaurantPrice * numbPiople) + barPrice + djPricee;
	}

	int One_night_pleasure(int numbPiople, int alcoholType, int roomQuality, int numbersRooms)
	{
		int barPrice = _bar.AlcoholQuality(alcoholType, numbPiople);
		int djPricee = _bar.DJShow(numbPiople);
		int hotelPrice = _hotel.BookRoom(roomQuality, numbersRooms);
		return barPrice + djPricee + hotelPrice;
	}

	int Holidays_pleasure(int numbersHoursPool, int numbersHoursBilloard, int numbPiople, int alcoholType, int numbersTable,  int roomQuality, int numbersRooms)
	{
		int poolPrice = _pool.RentPool(numbersHoursPool, numbPiople);
		int billiardPrice = _billiard.RentBilliard(numbersHoursBilloard, numbersTable);
		int restaurantPrice = _restaurant.Complex();
		int massagePrice = _massage.MassageSession(numbPiople);
		int barPrice = _bar.AlcoholQuality(alcoholType, numbPiople);
		int djPricee = _bar.DJShow(numbPiople);
		int hotelPrice = _hotel.BookRoom(roomQuality, numbersRooms);
		
		return poolPrice + billiardPrice + (restaurantPrice * 2 * numbPiople) + massagePrice + (barPrice * 2) + (djPricee * 2)
			+ (hotelPrice * 2);
	}
};

int main()
{
	ObarivResortFasad resortFasad;
	int resortPrice = resortFasad.Holidays_pleasure(3,4,6,1,2,2,3);
	cout << "Price: " << resortPrice << endl;


	system("pause");
	return 0;
}