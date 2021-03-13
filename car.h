#include <string>
#include <iostream>
#include <random>
#include <ctime>
#include <cmath>


using namespace std;

class car
{

public:
	///constructor and destructor
   car(){ next = NULL; ID = 0; make = "none"; x = 0; y = 0; face = 2; speed = 10; Dx = 0; Dy = 0; }
	~car(){}
	/// accessors and mutators
	void setID(int i){ ID = i; }
	void setNext(car * n){ next = n; }
	void setMake(string m){ make = m; }
	void setX(int i){ x = i; }
	void setY(int i){ y = i; }
	void setFace(int i){ face = i; }
	void setSpeed(int i){ speed = i; }
	void setDx(int i){ Dx = i; }
	void setDy(int i){ Dy = i; }

	string getMake(){ return make; }
	int getX(){ return x; }
	int getY(){ return y; }
	int getFace(){ return face; }
	int getSpeed(){ return speed; }
	int getDx(){ return Dx; }
	int getDy(){ return Dy; }
	int getID(){ return ID; }
	car * getNext(){ return next; }


void racetrack(default_random_engine*gptr, int l){


      normal_distribution<double> Mdist(0, 3);
      //int p=N;
		double s=10;
		int fileNum = 0;
		string FN;
		string basename = "car";
		string filename;
		int leg, lap = 0, EndLeg;
		double x, y, xdest, ydest;
		int path[8][2];
		int RaceLaps = l;




    fstream fin, fout;
    fin.open("racetrack_data.txt", ios::in);

    //fout1<<"plot'racetrack_data.txt' with linespoints,'car1.txt' with points pointtype 3 linecolor rgb \"#00ff00\",'car2.txt' with points pointtype 3 linecolor rgb \"#0000FF\",'car3.txt' with points pointtype 4 linecolor rgb \"#ffd700\",'car4.txt' with points pointtype 5 linecolor rgb \"#ff0000\""<<endl;
        string GN=to_string(ID);
		filename = basename+GN+".txt";




    for(int i=0; i<8; i++)
      {
        for(int j=0; j<2; j++)
        {
            fin>>path[i][j];
            //cout<<path[i][j];
            //if(j==0){cout<<", ";}
            //else{cout<<endl;}
        }
      }
    //cout<<"init the sim"<<endl;
    leg = 0;
     EndLeg = leg+1;

    x = path[leg][0]; ///starting position;
    y = path[leg][1];
    xdest=path[EndLeg][0];///first destination
    ydest=path[EndLeg][1];

    ///first filename
   /* FN = to_string(fileNum);
    fileNum++;
    filename = basename+FN+".txt"; */

    fout.open(filename.c_str(),ios::out);
      fout << x << " " << y << endl;

		///big triangle

		double Dx,Dy,D,dx,dy;

		Dx = xdest - x;
		Dy = ydest - y;
        D = sqrt(pow(Dx, 2) + pow(Dy, 2));


while (lap <= RaceLaps)

		{
              for(int L=0; L<8; L++){
                 while (D>s)


				{
				    dx = s*Dx / D;
                    x = x + dx + Mdist(*gptr);
                    dy = s*Dy / D;
                    y = y + dy + Mdist(*gptr);


                    //cout<<"car ID "<<ID<<endl;
					cout << "current position: " << x << ", " << y << endl;

                /*FN = to_string(fileNum);
					fileNum++; */
                    filename =basename+GN+ ".txt";

                    ///output x,y to filename
                   //fout.open(filename.c_str(), ios::out);
		           fout << x << " " << y << endl;


					//system("gnuplot track_command2.txt");
					Dx = xdest - x;
					Dy = ydest - y;
					D = sqrt(pow(Dx, 2) + pow(Dy, 2));
					}

				// arrived at destination
///get new destinations from path[][]
        leg++;
        leg = leg%8;
        EndLeg = leg+1;
        EndLeg = EndLeg%8;
        ///keeps it 0 to 7
        x = path[leg][0];
        y = path[leg][1];
        xdest = path[EndLeg][0];
        ydest = path[EndLeg][1];

        cout<<"start: "<<x<<", "<<y<<endl;
        cout<<"Dest : "<<xdest<<", "<<ydest<<endl;
        Dx = xdest - x;
        Dy = ydest - y;
        D = sqrt( pow(Dx,2) + pow(Dy,2) );
        }///end of "L" loop
    cout<<"END OF LAP #"<<lap<<endl;

    lap++;
		}

}

private:
	string make;
	int  x, y, Dx, Dy;
	int face;
	int speed;
	int ID;
	car * next;

	///protected:  not used right now

};
