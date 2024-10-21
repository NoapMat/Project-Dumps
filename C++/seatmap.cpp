#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// constants and inits glob vars.
const int ROWS = 10;
const int SEATS_PER_ROW = 10;
const float TICKET_PRICE = 15.26;
string MOVIE_TITLE = "Bocchi The Rock Re: Re:";
string GENRE = "Band";
int DURATION = 148;

void dispDetails() {
    cout << "---------------- Movie Details ---------------" << endl;
    cout << "Title: \"" << MOVIE_TITLE << "\"" << endl;
    cout << "Genre: " << GENRE << endl;
    cout << "Duration: " << DURATION << " minutes" << endl;
    cout << "Ticket Price: $" << fixed << setprecision(2) << TICKET_PRICE << endl;
    cout << endl;
}

void dispSeat(vector<vector<char>> &mapSeats) {
    cout << "------------------ SEAT MAP ------------------" << endl;
    cout << "      ";
    for (int j = 0; j < SEATS_PER_ROW; ++j) {
        cout << setw(3) << j + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < ROWS; ++i) {
        cout << "Row " << setw(2) << i + 1 << ": ";
        for (int j = 0; j < SEATS_PER_ROW; ++j) {
            if (mapSeats[i][j] == 'O') {
                cout << "[ ] ";
            } else {
                cout << "[X] ";
            }
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

bool reserveSeat(vector<vector<char>> &mapSeats, int row, int seat) {
    if (mapSeats[row-1][seat-1] == 'X') {
        cout << "Seat already reserved! Please select another seat." << endl;
        return false;
    } else {
        mapSeats[row-1][seat-1] = 'X';
        cout << "Seat reserved successfully..." << endl << endl;
        return true;
    }
}

void dispTicket(int row, int seat) {
    cout << endl << "--------------- Ticket Details ----------------" << endl;
    cout << "Title: \"" << MOVIE_TITLE << "\"" << endl;
    cout << "Seat: Row " << row << ", Seat " << seat << endl;
    cout << "Ticket Price: $" << fixed << setprecision(2) << TICKET_PRICE << endl;
    cout << "-----------------------------------------------" << endl;
}

void randmizer(vector<vector<char>> &mapSeats, int numReserved) {
    // randomizer based on time
    srand(time(0));
    for (int i = 0; i < numReserved; ++i) {
        int row = rand() % ROWS;
        int seat = rand() % SEATS_PER_ROW;
        if (mapSeats[row][seat] == 'O') {
            mapSeats[row][seat] = 'X';
        } else {
            // decrement when it is reserved
            --i;
        }
    }
}

int main() {
    vector<vector<char>> mapSeats(ROWS, vector<char>(SEATS_PER_ROW, 'O'));
    int row, seat;
    // initialize randomly reserved seats
    int rm_seats = 15;
    dispDetails();
    randmizer(mapSeats, rm_seats);
    dispSeat(mapSeats);
    bool isReserved = false;
    while (!isReserved) {
        cout << "Reserve seat (row, seat number): ";
        // takes 2 arguments
        cin >> row >> seat;
        isReserved = reserveSeat(mapSeats, row, seat);
    }
    dispSeat(mapSeats);
    dispTicket(row, seat);
    return 0;
}
