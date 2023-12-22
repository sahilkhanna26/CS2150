#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);
 float dist = 999999999;
vector<string> v1;


/**
 * @brief This program is a brute force solution to the traveling salesperson problem
 * @param a width 
 * @param b height
 * @param c num of cities
 * @param d random seec
 * @param e the num of cities to visit
 * @return The minimum distance to traverse x cities
 * @author Sahil Khanna (sk5xvh)
 * @file traveling.cpp   
 * 
 */

// I was helped by a TA on parts of this code in Lab time on tuesday April 26.

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    

    // TODO: YOUR CODE HERE

   
    string s = dests.at(0);
    string s1 = dests.at(1);

    sort(dests.begin()+1, dests.end());
    

    do{

        computeDistance(me, s, dests);
    }while(next_permutation(dests.begin()+1, dests.end()));

    printRoute(s,v1);
   //dist = computeDistance(me, s, dests);
   

    // vector<string> other_cities;

    // for (auto newItr =  dests.begin()+1; newItr!= dests.end(); newItr++){
    //     string city = *newItr;
    //     other_cities.push_back(city);
    //     //cout<< city<<endl;
    // }


    // while(next_permutation(other_cities.begin(), other_cities.end())){

       
    //     v1.push_back(s);
    //     for (auto perItr= other_cities.begin();perItr!= other_cities.end(); perItr++){
    //         string mid_city = *perItr;
    //         v1.push_back(mid_city);


    //     }

    //     float min_dist = computeDistance(me, s, v1);
       
    // }



    // cout<< dist;









    



    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth & me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    // vector<string> v;
    // v.push_back(start);
    // for (auto itr2= dests.begin(); itr2!= dests.end(); itr2++){
    //     v.push_back(*itr2);
    // }
    // v.push_back(start);

    string start2 = start;

    float total_distance = 0.0;

    // for (auto itr3= dests.begin(); itr3!= dests.end(); itr3++){
    //     // auto itr4 = itr3 +1;
    //      string city1= *itr3;
    //     // string city2 = *itr4;
    //     float distance1= me.getDistance(start2,city1);
    //     start2 = city1;
    //     total_distance = total_distance+ distance1;
    // }
    for(int i = 0; i<dests.size(); i++){
        total_distance+= me.getDistance(start2,dests.at(i));
        start2 = dests.at(i);
    }
    total_distance+=me.getDistance(dests.at(dests.size()-1),start);
    if( total_distance < dist){
            dist = total_distance;
            v1 = dests;
        }
    return total_distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    cout<< "Minimum path has distance: "<< dist<<": ";
    for (auto itr= v1.begin(); itr!= v1.end(); itr++){
        cout<< *itr<< " -> ";
    }
    
    cout<< start<<endl;
}