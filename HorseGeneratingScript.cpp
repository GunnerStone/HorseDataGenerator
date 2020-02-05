// HorseGeneratingScript.cpp 
// Gunner Stone 
// Febuary 4 2020
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> generateData(const string filename);

int main()
{
	///Define names of files
	const string horseRandNameFile = "names.txt";
	const string horseImgPathFile = "imagePaths.txt";
	const string colorsFile = "colors.txt";
	const string manesFile = "manes.txt";
	const string facesFile = "faces.txt";
	const string whorlsFile = "whorls.txt";
	const string feetFeaturesFile = "feetFeatures.txt";
	const string locationsFile = "locations.txt";
	const string dartingStatusFile = "dartingStatus.txt";
	const string dartingDatesFile = "dartingDates.txt";
	const string JSONHorseData = "horseData.json";
	
	///Define number of horse bands 
	//If a horse has a unique band id that is not shared by another horse, it is alone (not in a band)
	//this value should not be set to <= 0 or program will not work
	const int BANDSIZE = 20;

	///Define vectors to store data selections
	vector<string>myNames;
	vector<string>myImagePaths;
	vector<string>myColors;
	vector<string>myManes;
	vector<string>myFaces;
	vector<string>myWhorls;
	vector<string>myFeetFeatures;
	vector<string>myLocations;
	vector<string>myDartingStatuses;
	vector<string>myDartingDates;

	cout << "==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==\n";
	cout << "= Initializing Horse Data Generation Script =\n";
	cout << "==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==\n";
	
	///Generate Random Names
	cout << "Loading Names\n";

	auto startTime = high_resolution_clock::now();
	myNames = generateData(horseRandNameFile);
	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myNames.size() << " random Names from filename: \""<< horseRandNameFile<< "\" in "<<(duration.count()/ 1000000.0) << " seconds\n";

	///Generate Random ImagePaths
	cout << "Loading Image Paths\n";

	startTime = high_resolution_clock::now();
	myImagePaths = generateData(horseImgPathFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myImagePaths.size() << " random ImagePaths from filename: \"" << horseImgPathFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";


	///Generate Random Colors
	cout << "Loading Colors\n";

	startTime = high_resolution_clock::now();
	myColors = generateData(colorsFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myColors.size() << " random Colors from filename: \"" << colorsFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";

	///Generate Random Manes
	cout << "Loading Manes\n";

	startTime = high_resolution_clock::now();
	myManes = generateData(manesFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myManes.size() << " random Manes from filename: \"" << manesFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";

	///Generate Random Faces
	cout << "Loading Faces\n";

	startTime = high_resolution_clock::now();
	myFaces = generateData(facesFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myFaces.size() << " random Faces from filename: \"" << facesFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";

	///Generate Random Whorls
	cout << "Loading Whorl\n";

	startTime = high_resolution_clock::now();
	myWhorls = generateData(whorlsFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myWhorls.size() << " random Whorls from filename: \"" << whorlsFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";

	///Generate Random FeetFeatures
	cout << "Loading FeetFeatures\n";

	startTime = high_resolution_clock::now();
	myFeetFeatures = generateData(feetFeaturesFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myFeetFeatures.size() << " random FeetFeatures from filename: \"" << feetFeaturesFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";

	///Generate Random Locations
	cout << "Loading Locations\n";

	startTime = high_resolution_clock::now();
	myLocations = generateData(locationsFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myLocations.size() << " random Locations from filename: \"" << locationsFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";

	///Generate Random Darting Statuses
	cout << "Loading Darting Statuses\n";

	startTime = high_resolution_clock::now();
	myDartingStatuses = generateData(dartingStatusFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myDartingStatuses.size() << " random DartingStatuses from filename: \"" << dartingStatusFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";
	
	///Generate Random Darting Dates
	cout << "Loading Darting Dates\n";

	startTime = high_resolution_clock::now();
	myDartingDates = generateData(dartingDatesFile);
	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "Successfully loaded " << myDartingDates.size() << " random DartingDates from filename: \"" << dartingDatesFile << "\" in " << (duration.count() / 1000000.0) << " seconds\n";


	///Ask user for desired number of generated hore data
	int numHorses;
	cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=\n";
	cout << "Enter number of horses to generate: ";
	cin >> numHorses;
	cout << "==-=-=-=-=-=-=-=-=-=-=-==\n";
	cout << "= Generating Horse Data =\n";
	cout << "==-=-=-=-=-=-=-=-=-=-=-==\n";
	startTime = high_resolution_clock::now();

	//output filestream that will contain generated json horse data
	ofstream myfile;
	myfile.open(JSONHorseData);

	//Generate Random Seed to pull random data
	srand(time(NULL));
	int random;

	//Beginning of JSON 
	myfile << "{\"horses\":[";
	//Body of JSON
	for (int i = 0; i < numHorses; i++)
	{
		//Start an Element
		myfile << "{\n";
		
		myfile << "\t\"id\": " << i << ",\n";

		random = rand() % myNames.size();
		myfile << "\t\"Name\": \"" << myNames.at(random) << "\",\n";

		random = rand() % myImagePaths.size();
		myfile << "\t\"Image\": \"" << myImagePaths.at(random) << "\",\n";

		random = rand() % BANDSIZE;
		myfile << "\t\"Band\": \"" << random << "\",\n";
		
		random = rand() % myColors.size();
		myfile << "\t\"Color\": \"" << myColors.at(random) << "\",\n";
		
		random = rand() % myManes.size();
		myfile << "\t\"Mane\": \"" << myManes.at(random) << "\",\n";
		
		random = rand() % myWhorls.size();
		myfile << "\t\"Whorl\": \"" << myWhorls.at(random) << "\",\n";
		
		random = rand() % myFeetFeatures.size();
		myfile << "\t\"rfFeet\": \"" << myFeetFeatures.at(random) << "\",\n";
		
		random = rand() % myFeetFeatures.size();
		myfile << "\t\"rrFeet\": \"" << myFeetFeatures.at(random) << "\",\n";
		
		random = rand() % myFeetFeatures.size();
		myfile << "\t\"lfFeet\": \"" << myFeetFeatures.at(random) << "\",\n";
		
		random = rand() % myFeetFeatures.size();
		myfile << "\t\"lrFeet\": \"" << myFeetFeatures.at(random) << "\",\n";
		
		random = rand() % myLocations.size();
		myfile << "\t\"Location\": \"" << myLocations.at(random) << "\",\n";
		
		random = rand() % myDartingStatuses.size();
		myfile << "\t\"DartStatus\": \"" << myDartingStatuses.at(random) << "\",\n";
		
		random = rand() % myDartingDates.size();
		myfile << "\t\"DartDate\": \"" << myDartingDates.at(random) << "\"\n";


		myfile << "}";
		//If there are more horses to process, create syntax to account for more elements
		if (i + 1 < numHorses)
			myfile << ", ";
	}
	myfile << "]}";
	myfile.close();

	stopTime = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stopTime - startTime);

	///Display feedback to user
	cout << "Successfully Generated " << numHorses << " random Horses into filename: \"" << JSONHorseData << "\" in " << (duration.count() / 1000000.0) << " seconds\n";
	system("pause");
}


/************************************************
* Given a valid filename, this function 
* will parse each line as a string and return all
* parsed strings back as a vector<string>
*************************************************/
vector<string> generateData(const string filename)
{
	//vector to store string data
	vector<string> dataList;

	//input filestream that contains random names
	ifstream myFile;
	myFile.open(filename);

	//add names to vector
	string tempName;
	while (myFile.good())
	{
		getline(myFile, tempName);
		dataList.push_back(tempName);
	}

	return dataList;
}