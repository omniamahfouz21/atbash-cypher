#include <iostream>
using namespace std ;
int main (){
class AtbashTable ;
{
    /// <summary>
    /// Lookup table to shift characters.
    /// </summary>
    char[] _shift = new char[char.MaxValue];

    /// <summary>
    /// Generates the lookup table.
    /// </summary>
    public AtbashTable()
    {
	// Set these as the same.
	for (int i = 0; i < char.MaxValue; i++)
	{
	    _shift[i] = (char)i;
	}
	// Reverse order of capital letters.
	for (char c = 'A'; c <= 'Z'; c++)
	{
	    _shift[(int)c] = (char)('Z' + 'A' - c);
	}
	// Reverse order of lowercase letters.
	for (char c = 'a'; c <= 'z'; c++)
	{
	    _shift[(int)c] = (char)('z' + 'a' - c);
	}
    }

    /// <summary>
    /// Apply the Atbash cipher.
    /// </summary>
    public string Transform(string value)
    {
	try
	{
	    // Convert to char array
	    char[] a = value.ToCharArray();
	    // Shift each letter.
	    for (int i = 0; i < a.Length; i++)
	    {
		int t = (int)a[i];
		a[i] = _shift[t];
	    }
	    // Return new string.
	    return new string(a);
	}
	catch
	{
	    // Just return original value on failure.
	    return value;
	}
    }
}
}
