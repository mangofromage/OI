#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include <array>
#include <utility>
#include <streambuf>
using namespace std;

//template <class T>

// string to_string1(T t)
// {
//     stringstream ss;
//     ss << t;
//     return ss.str();
// }

string removeLastWhiteChars(string source)
{
  string response = "";
  for(int i = source.size() - 1; i >= 0; --i)
  {
    if(source[i] >= 48 && source[i] <= 57) response = source[i] + response;
  }
  return response;
}

string exec(const char *cmd)
{
  array<char, 128> buffer;
  string result;
  shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
  if(!pipe) throw runtime_error("popen() failed.");
  while(!feof(pipe.get()))
  {
    if(fgets(buffer.data(), 128, pipe.get()) != nullptr)
    {
      result += buffer.data();
    }
  }
  return result;
}

int getAllFileNames(string directoryPath, vector<string> &filenames)
{
  //cout << "dir pa " << directoryPath << endl;
  DIR *dp;
  struct dirent *dirp;
  if((dp = opendir(directoryPath.c_str())) == NULL)
  {
    //cout << "dir path new " << directoryPath.c_str() << "end" << endl;
    return errno;
  }
  while((dirp = readdir(dp)) != NULL)
  {
    filenames.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}

void close(string message)
{
  close(message.c_str());
}

void close(const char *message)
{
  cout << message << endl << "Gonna close" << endl;
  exit(0);
}

string setSlahsesSpaces(string source)
{
  //cout << "setset" << endl;
  string response = "";
  for(int i = 0; i < source.size(); ++i)
  {
    if(source[i] == char(32))
    {
      response += '\\';
      response += " ";
      //cout << "call" << endl;
    }
    else response += source[i];
    //cout << "call call" << endl;
  }
  return response;
}

string cutLast(string source, int count)
{
  if(source.size() < count) return "";
  string out = "";
  for(int i = 0; i < source.size() - count; ++i)
  {
    out += source[i];
  }
  return out;
}

void findIfExist(string filename)
{
  //filename = setSlahsesSpaces(filename);
  string FindCommand = "find " + filename;
  //cout << "command " << FindCommand << endl;
  if(system(FindCommand.c_str()) != 0) close("Could not find file.");
}

class InFile
{
protected:
  string path = "";
  string filename = "";

  pair<string, string> separatePathAndName(string path)
  {
    string pa = "";
    string name = "";
    int i = path.size() - 1;
    for(; i >= 0 && path[i] != '/'; --i)
    {
      name = path[i] + name;
    }
    pa = cutLast(path, path.size() - i);
    cout << "name " << name << "\npath " << pa << endl;
    return make_pair(name, pa);
  }

public:
  InFile(string);
};

InFile::InFile(string filePath)
{
  findIfExist(filePath);
  pair<string, string> fp = separatePathAndName(filePath);
  if(fp.first.size() == 0) close("Error separating filename from path.");
  filename = fp.first;
  path = fp.second;
}

class IOfiles : public InFile
{
protected:
  vector<pair<string, string>> ioFileNames;

  void pushIOfilesPairs(vector<pair<string, string>> &iof, vector<string> in, vector<string> out)
  {
    for(int i = 0; i < in.size(); ++i)
    {
      string infilename = cutLast(in[i], 3);
      //cout << "infilename " << infilename << endl;
      for(int k = 0; k < out.size(); ++k)
      {
        if(infilename == "." || infilename == ".." || infilename.size() == 0)
        {
          //cout << "break ." << endl;
          break;
        }

        string outfilename = cutLast(out[i], 4);
        if(infilename == outfilename)
        {
          iof.push_back(make_pair(infilename + ".in", outfilename + ".out"));
          break;
        }
        cout << "Could not find out file for " << infilename << endl;
      }
    }
  }

public:
  IOfiles(string filePath) : InFile(filePath)
  {
    vector<string> infilenames;
    vector<string> outfilenames;
    int erno = 0;
    if((erno = getAllFileNames(path + "in", infilenames)) != 0)
    {
      cout << "err no " << erno << " number of readed " << infilenames.size() << endl;
      close("Unknown error reading infiles.");
    }
    if(getAllFileNames(path + "out", outfilenames) != 0) close("Unknown error reading outfiles.");

    sort(infilenames.begin(), infilenames.end());
    sort(outfilenames.begin(), outfilenames.end());

    cout << "File names readed\nIn files  : " << infilenames.size() << "\nOut files : " << outfilenames.size() << endl;

    pushIOfilesPairs(ioFileNames, infilenames, outfilenames);

    cout << "IO pairs  : " << ioFileNames.size() << endl;
  }
};

class Program : public IOfiles
{
protected:
  int ok = 0;
  int failed = 0;
  int total = 0;
  string compiledName = "";
public:
  Program(string filePath) : IOfiles(filePath)
  {
    // ok = 0;
    // failed = 0;
    // total = 0;
  }
  void Compile();
  void RunTests();
  int Passed = [&]() -> int {return ok;}();
  int Failed = [&]() -> int {return failed;}();
  int Total = [&]() -> int {return total;}();
};

void Program::Compile()
{
  compiledName = cutLast(filename, 4);
  string compileString = "g++ -Wall -std=c++11 " + filename + " -o " + compiledName;
  cout << "Compiling file" << endl;
  cout << compileString << endl;
  if(system(compileString.c_str()) != 0) close("Error durning compilation.");
  cout << "Probably compilation OK." << endl;
}

void Program::RunTests()
{
  for(int i = 0; i < ioFileNames.size(); ++i)
  {
    string command = "./" + compiledName + "<in/" + ioFileNames[i].first;
    cout << ioFileNames[i].first << endl;
    string result = exec(command.c_str());
    result = removeLastWhiteChars(result);
    cout << "output   " << result << endl;

    string outfile = "out/" + ioFileNames[i].second;
    ifstream t(outfile.c_str());
    string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    string response = removeLastWhiteChars(str);
    cout << "expected " << response << endl;

    if(result != response)
    {
      cout << "FAILED!!!\n" << endl;
      ++failed;
    }
    else
    {
      ++ok;
      cout << "ok " << ok << endl;
      cout << "OK!!!\n" << endl;
    }
    ++total;
  }

}

int main(int argc, char const *argv[])
{
  if(argc != 2)
  {
    if(argc < 2) close("No file selected.");
    close("Too many agruments");
  }

  Program test(setSlahsesSpaces(argv[1]));
  test.Compile();
  test.RunTests();
  // findIfExist(argv[1]);

  cout << "Passed : " << test.Passed << "\nFailed : " << test.Failed << "\nTotal  : " << test.Total << endl;

  return 0;
}
