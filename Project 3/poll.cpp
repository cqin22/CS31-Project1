#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.
bool isValidStateCode(string stateCode)
{
  const string codes =
      "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
      "LA.ME.MA.MD.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
      "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
  return (stateCode.size() == 2 && stateCode.find('.') == string::npos && // no '.' in stateCode
          codes.find(stateCode) != string::npos);                         // match found
}

// returns true if PollString follows rules in spec
bool isValidPollString(string pollData)
{
  int comma = 0;
  int element = 0; // location
  string vote;
  int i = 0;

  if (pollData == "")
    return true;
  if (pollData[pollData.size() - 1] == ',')
    return false;
  pollData += ',';

  // counts number of commas in the poll data string
  for (int j = 0; j <= pollData.size(); j++)
  {
    if (pollData[j] == ',')
      comma++;
  }

  // stops the code when all state forecasts have been validated using comma count
  while (comma > 0)
  {

    pollData[element] = toupper(pollData[element]);
    pollData[element + 1] = toupper(pollData[element + 1]);

    // validates state code for given state forecasst
    if (!isValidStateCode(pollData.substr(element, 2)))
      return false;

    element += 2;

    while (pollData[element] != ',')
    {
      i = 0;
      while (!isalpha(pollData[element + i]))
        i++;
      vote = pollData.substr(element, i + 1); // splits string into substrings

      if (pollData[element] == ',')
        element += 2;
      else if (!isdigit(pollData[element]))
        return false;
      else
      {
        // if party result is size 2: first charater must be #, and next char must be # or party code
        if (vote.size() == 2)
        {
          if (!isdigit(vote[0]))
            return false;
          else if (!isalpha(vote[1]))
            return false;
          element += 2;
        }

        // if party result is size 3: first two characters must be #, and next char must be party code
        else if (vote.size() == 3)
        {
          if (!isdigit(vote[0]))
            return false;
          else if (!isdigit(vote[1]))
            return false;
          else if (!isalpha(vote[2]))
            return false;
          element += 3;
        }

        // checks for a state forecast with no party results
        else if (vote.size() == 0)
        {
          continue;
        }

        else
          return false;
      }
    }
    comma -= 1;
    element++;
  }
  return true;
}

int countSeats(string pollData, char party, int &seatCount)
{
  // validates first 2 paramters
  if (!isValidPollString(pollData))
    return 1;
  if (!isalpha(party))
    return 2;

  else
  {
    party = toupper(party);
    seatCount = 0;

    // parses every character in pollData to find party match, then adds party result to seatCount
    for (int i = 0; i < pollData.size(); i++)
    {
      if (isalpha(pollData[i]) && isalpha(pollData[i + 1]))
        i += 2;
      else if (isalpha(pollData[i]))
        pollData[i] = toupper(pollData[i]);
      if (pollData[i] == party)
      {
        // adds digits depending on 1 or 2 digits before the party code
        if (isdigit(pollData[i - 2]))
        {
          // does not work: string str_seat_count = pollData[i-2] + pollData[i-1];
          string str_seat_count = pollData.substr(i - 2, 2);
          seatCount += stoi(str_seat_count);
          // does not work:: seatCount += stoi("333")
          // does not work:: seatCount += stoi(pollData[i - 2]);
          // does not work:: seatCount += stoi(pollData[i - 1]);
        }
        else
          // does not work: string str_seat_count = pollData.substr(i-1, 1);
          // does not work: seatCount += stoi(str_seat_count);
          seatCount += pollData[i - 1] - '0';
      }
    }

    return 0;
  }
}

int main()
{
  int seats = -100;
  if (isValidPollString("CA34D12R2I,nV9R,vt,Ny3r9I13D"))
    cerr << "Passed test 1: isValidPollString(\"CA34D12R2I,nV9R,vt,Ny3r9I13D\")" << endl;
  if (isValidPollString(""))
    cerr << "Passed test 2: isValidPollString(\"\")" << endl;
  if (isValidPollString("CT5D,NY9R16D1I,VT,ne3r00D"))
    cerr << "Passed test 3: isValidPollString(CT5D,NY9R16D1I,VT,ne3r00D)" << endl;
  if (!isValidPollString("ZT5D,NY9R16D1I,VT,ne3r00D"))
    cerr << "Passed test 4: !isValidPollString(ZT5D,NY9R16D1I,VT,ne3r00D)" << endl;
  if (!isValidPollString("CT5D,NY9R16D1I,VT,Re3r00D"))
    cerr << "Passed test 5: !isValidPollString(CT5D,NY9R16D1I,VT,Re3r00D)" << endl;
  if (!isValidPollString("CT5D,CY9R16D1I,Re3r00D"))
    cerr << "Passed test 6: !isValidPollString(CT5D,CY9R16D1I,Re3r00D)" << endl;
  if (!isValidPollString("CT5D,"))
    cerr << "Passed test 7: !isValidPollString(CT5D,)" << endl;
  if (countSeats("CA34D12R2I,nV9R,vt,Ny3r9I13D", 'd', seats) == 0 && seats == 47)
    cerr << "project done" << endl;
  return 0;
}
