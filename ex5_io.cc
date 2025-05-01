
// Input-output functions for Ex 5ABC: Entropy of a solid using the Einstein model

#include "ex5.h"

// GetInput: read the input file and store that is read into the appropriate variables
//           (arguments: integer switch, temperature, number of steps, initial seed for
//           the random-number generator, Einstein temperature, gas constant, name of
//           output file); return true if all went well, false otherwise [the function
//           definition is in file ex5_io.cc]
bool GetInput(int& switch_case, double& T, int& num_steps, int& seed,
              double& T_E, double& R, string& output_file_name) {
    cout << "# GetInput was called!" << endl;
    cout << "# Please insert the switch value: " << endl;
    cin >> switch_case;
    cout << "# " << switch_case << endl;
    cout << "# Please insert the Value of the temperature T in [K]: " << endl;
    cin >> T;
    cout << "# " << T << endl;
    cout << "# Please insert the Number of intervals or iterations: " << endl;
    cin >> num_steps;
    cout << "# " << num_steps << endl;
    cout << "# Please insert the seed value: " << endl;
    cin >> seed;
    cout << "# " << seed << endl;
    cout << "# Please insert the Value of the Einstein temperature T_E in [K]: " << endl;
    cin >> T_E;
    cout << "# " << T_E << endl;
    cout << "# Please insert the Value of the gas constant R in [J/(K mol)]: " << endl;
    cin >> R;
    cout << "# " << R << endl;
    cout << "# Please insert Name of the output file: " << endl;
    cin >> output_file_name;
    cout << "# " << output_file_name << endl;
    if (switch_case <= 5 && switch_case >= 1 && seed > 0 && T >= 0 && T_E >= 0 && R >= 0 && num_steps > 0) {
        cout << "# Valid input." << endl;
        cout << "# # #" << endl;
        return true;
    } else if (switch_case == 5 && num_steps >= 0) {
        cout << "# Valid input." << endl;
        cout << "# # #" << endl;
        return true;
    }
    return false;
}

// WriteTable: write a two column data table to a specified file (arguments: file name, number of
//             values in the data table, data table of dimension tab[num_val][2]); no return value:
//             the function directly exits with an error if there is an I/O problem
//             [the function definition is in file ex5_io.cc]
void   WriteTable(string output_file_name, int num_values, double table[][2]) {
    cout << "# WriteTable was called!" << endl;
    ofstream out(output_file_name);
    // check if the file is open
    if (!out.is_open()) {
        cout << "# Error: Unable to open file: " << output_file_name << endl;
        return;
    }
    cout << "# Writing values to file... " << output_file_name << endl;
    for (int i = 0; i < num_values; i++) {
      out << table[i][0] << " " << table[i][1] << endl;
    }
    out.close();
    cout << "# Happily created the file: " << output_file_name << endl;
    return;
}
