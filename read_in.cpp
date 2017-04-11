#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "prototypes.h"

using namespace std;

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function read all parameters in from parameter.in, check the reasonability, and then store them into login file, out to the screen as well as to the program memory.
 *
 * Return             0 on sucess
 *
 * Return             EXIT_FAILURE when parameter.in is wrong.
 */

int read_in_parameters(int argc, char* argv[], string *model_name, string *force_type,
                      float *alpha, float *beta, float *time_step, float *total_time,
                      string *waveform, float *area_x, float *area_y, int *n_x, int *n_y,
                      float *moment, ifstream &infile, int flag)
{
    int i = 0, flag1 = 0, flag2 = 0;
    string str[1000], s, variable_name;

    // Open the input file and prepare to read parameters in
    infile.open(argv[1]);
    
    // Check if file is successfully open
    check_file_open(infile, flag1);

    // Read variables as strings from infile
    while( infile >> s )
    {
        str[i] = s;
        i++;
    }
    
    // Finish reading, infile closed.
    infile.close();

    cout << "Start reading variables to memory\n";
  
    i = 0;

    while(str[i] != "")
    {
        if(str[i] == "model_name")
        {
            read_string(str, i, variable_name, *model_name);
        }
        
        if(str[i] == "force_type")
        {
            read_string(str, i, variable_name, *force_type);
        }
        
        if(str[i] == "alpha")
        {
            read_float(str, i, variable_name, *alpha);
        }
        
        if(str[i] == "waveform")
        {
            read_string(str, i, variable_name, *waveform);
        }
        
        if(str[i] == "beta")
        {
            read_float(str, i, variable_name, *beta);
        }

        if(str[i] == "time_step")
        {
            read_float(str, i, variable_name, *time_step);
        }
        
        if(str[i] == "total_time")
        {
            read_float(str, i, variable_name, *total_time);
        }
        
        if(str[i] == "area_x")
        {
            read_float(str, i, variable_name, *area_x);
        }
        
        if(str[i] == "area_y")
        {
            read_float(str, i, variable_name, *area_y);
        }
        
        if(str[i] == "n_x")
        {
            read_int(str, i, variable_name, *n_x);
        }
        
        if(str[i] == "n_y")
        {
            read_int(str, i, variable_name, *n_y);
        }
        
        if(str[i] == "moment")
        {
            read_float(str, i, variable_name, *moment);
        }
        
        i++;
    }
    
    check_variables(alpha, beta, time_step, total_time, area_x, area_y, n_x, n_y, moment, flag2);
    
    flag = flag1 + flag2;
    
    return flag;
}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function used for reading variables in memory, print to screen
 *
 * Return             0 on sucess
 *
 */

int read_string(string str[], int i, string variable_name, string &string_value)
{

    variable_name = str[i];
    cout << variable_name << "=\t" << endl;

    string_value = str[i+1];
    cout << string_value << endl << "\n";
    
    return 0;
}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function float inputs
 *
 * Return             0 on sucess
 *
 */

int read_float(string str[], int i, string variable_name, float &float_value)
{

    char* c;
    variable_name = str[i];
    cout << variable_name << "=\t" << endl;

    c = const_cast<char*>(str[i+1].c_str());
    sscanf(c, "%e", &float_value);
    cout << float_value << endl << "\n";
    return 0;
}

// read variables in as int

int read_int(string str[], int i, string variable_name, int &int_value)

{
    
    char* c;
    variable_name = str[i];
    cout << variable_name << "=\t" << endl;
    
    c = const_cast<char*>(str[i+1].c_str());
    sscanf(c,"%d", &int_value);
    cout << int_value << endl << "\n";
    
    return 0;
    
}

int out_login(string *model_name, string *force_type, float *alpha, float *beta, float *time_step,
              float *total_time, string *waveform, float *area_x, float *area_y, int *n_x,
              int *n_y, float *moment, ofstream &file)
{
    file << "model_name =\t" << model_name << endl;
    file << "force_type =\t" << force_type << endl;
    file << "alpha =\t" << alpha << endl;
    file << "beta =\t" << beta << endl;
    file << "time_step =\t" << time_step << endl;
    file << "total_time =\t" << total_time << endl;
    file << "waveform =\t" << waveform << endl;
    file << "area_x =\t" << area_x << endl;
    file << "area_y =\t" << area_y << endl;
    file << "n_x =\t" << n_x << endl;
    file << "n_y =\t" << n_y << endl;
    file << "moment =\t" << moment << endl;

    return 0;
}