#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<shlobj.h>

using namespace std;

int main() {
	string path; // Defines "path".
	path = getenv("localappdata"); // Gets %LOCALAPPDATA% Folder and links into "path".
	// cout << path + "\\DELTARUNE\\filech1_0" << endl; [Tells if the path is correctly, used in mid-development.]
	ifstream qFile(path + "\\DELTARUNE\\filech1_0"); // Reads File from "Path + Deltarune folder" and links into "qFile".
	string qLine; // Defines "qLine".

	if (!qFile.good()) { // If file isn't found,
		cout << "Could not find file..." << endl; // Print this to console.
		return 1; // Ends Process.
	}

	int cur_l = 0; // Start Line, used if "cur_l" is later equals to "end_l" to finish process.
	int end_l = 1; // End Line of what should get read.

	while (!qFile.eof()) {
		qFile >> qLine; // Copy text to "qLine" from the file "qFile".
		cout << qLine << " "; // Print to console and add spaces.
		{
			if (cur_l == end_l) { // If "cur_l" value matches "end_l"
				break; // end the loop.
			}
			cur_l++; // Add a value to "cur_l".
		}
	} // Loops if process is still running.

	qFile.close();

	Sleep(5000); // Sleep for 5 Seconds.

	return 0; // Ends Process.
}
