import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class CityMap
{
	public String getLegend(String[] cityMap, int[] POIs)
	{
            int letter[] = new int[128];
            int H, W;
            H = cityMap.length;
            W = cityMap[0].length();
            
            for(int i=0;i<H;i++)
            {
                for(int j=0;j<W;j++)
                {
                    if(cityMap[i].charAt(j)=='.') continue;
                    int temp = (int) cityMap[i].charAt(j);
                    letter[temp]++;
                }
            }
            String s="";
            for(int i=0;i<POIs.length;i++)
            {
                for(int j=65;j<=90;j++)
                    if(POIs[i]==letter[j])
                    {
                        //System.out.println((char) j);
                        s+=(char) j;
                        
                    }
            }
            return s;
            
		
	}
	
	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
	private static boolean KawigiEdit_RunTest(int testNum, String[] p0, int[] p1, boolean hasAnswer, String p2) {
		System.out.print("Test " + testNum + ": [" + "{");
		for (int i = 0; p0.length > i; ++i) {
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print("\"" + p0[i] + "\"");
		}
		System.out.print("}" + "," + "{");
		for (int i = 0; p1.length > i; ++i) {
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print(p1[i]);
		}
		System.out.print("}");
		System.out.println("]");
		CityMap obj;
		String answer;
		obj = new CityMap();
		long startTime = System.currentTimeMillis();
		answer = obj.getLegend(p0, p1);
		long endTime = System.currentTimeMillis();
		boolean res;
		res = true;
		System.out.println("Time: " + (endTime - startTime) / 1000.0 + " seconds");
		if (hasAnswer) {
			System.out.println("Desired answer:");
			System.out.println("\t" + "\"" + p2 + "\"");
		}
		System.out.println("Your answer:");
		System.out.println("\t" + "\"" + answer + "\"");
		if (hasAnswer) {
			res = answer.equals(p2);
		}
		if (!res) {
			System.out.println("DOESN'T MATCH!!!!");
		} else if ((endTime - startTime) / 1000.0 >= 2) {
			System.out.println("FAIL the timeout");
			res = false;
		} else if (hasAnswer) {
			System.out.println("Match :-)");
		} else {
			System.out.println("OK, but is it right?");
		}
		System.out.println("");
		return res;
	}
	public static void main(String[] args) {
		boolean all_right;
		all_right = true;
		
		String[] p0;
		int[] p1;
		String p2;
		
		// ----- test 0 -----
		p0 = new String[]{"M....M","...R.M","R..R.R"};
		p1 = new int[]{3,4};
		p2 = "MR";
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = new String[]{"XXXXXXXZXYYY"};
		p1 = new int[]{1,8,3};
		p2 = "ZXY";
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = new String[]{"...........","...........","...........","..........T"};
		p1 = new int[]{1};
		p2 = "T";
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 3 -----
		p0 = new String[]{"AIAAARRI.......GOAI.",".O..AIIGI.OAAAGI.A.I",".A.IAAAARI..AI.AAGR.","....IAI..AOIGA.GAIA.","I.AIIIAG...GAR.IIAGA","IA.AOA....I....I.GAA","IOIGRAAAO.AI.AA.RAAA","AI.AAA.AIR.AGRIAAG..","AAAAIAAAI...AAG.RGRA",".J.IA...G.A.AA.II.AA"};
		p1 = new int[]{16,7,1,35,11,66};
		p2 = "GOJIRA";
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
		
		if (all_right) {
			System.out.println("You're a stud (at least on the example cases)!");
		} else {
			System.out.println("Some of the test cases had errors.");
		}
	}
	// PROBLEM STATEMENT
	// Manao arrived to a city he's never been to. He bought a city map that depicts the city as a grid H squares high and W squares wide. Each square in this grid can either contain a street segment or a single point of interest of some type.
	// 
	// It was later when Manao noticed that the map lacked a legend. The map legend is the list of all types of points of interest (further referred to as POIs) present on the map. Each POI type is coupled with the corresponding symbol denoting this type on the map. For example, you might have seen an 'M' sign denoting a metro station or a fork-and-spoon sign denoting a restaurant on a city map.
	// 
	// Fortunately, not all is lost: the map contains a legend summary. The summary states how many POIs of each type are there on the map (for example, it could say: all in all, there are 9 restaurants and 4 metro stations on the map). Moreover, it turned out that all quantities are pairwise distinct. Manao realized that he could guess the signs using this information (for instance, if there were 4 triangle signs on the map Manao would know that triangle stands for a metro station).
	// 
	// You are given a String[] cityMap containing H elements, each of them W characters long. Each character of cityMap designates the corresponding square on Manao's city map and is '.' if there is a street segment in that square or an uppercase letter if the square contains a POI. Different types of POIs are denoted by different letters, two POIs of the same type are always denoted with the same letter. As you see, the letters just stand for the different signs on the map.
	// 
	// You are also given a int[] POIs. POIs[i] is the number of occurences of the i-th type POIs on the map. It is guaranteed that the information given is consistent, i.e. there are exactly as many different letters in cityMap as elements in POIs and there exists a valid assignment of letters to POI types.
	// 
	// For each POI type, determine the letter with which it is denoted on the map. Return a String of as many characters as elements in POIs, where the character at the i-th position is the letter corresponding to the i-th POI type.
	// 
	// DEFINITION
	// Class:CityMap
	// Method:getLegend
	// Parameters:String[], int[]
	// Returns:String
	// Method signature:String getLegend(String[] cityMap, int[] POIs)
	// 
	// 
	// CONSTRAINTS
	// -cityMap will contain between 1 and 50 elements, inclusive.
	// -Each element of cityMap will be between 1 and 50 characters long, inclusive.
	// -The elements of cityMap will be of the same length.
	// -Elements of cityMap will consist of '.' and 'A'-'Z' characters only.
	// -POIs will contain between 1 and 26 elements, inclusive.
	// -Each element of POIs will be between 1 and 2500, inclusive.
	// -All elements of POIs will be distinct.
	// -There will exist a valid assignment of letters in cityMap to POI types.
	// 
	// 
	// EXAMPLES
	// 
	// 0)
	// {"M....M",
	//  "...R.M",
	//  "R..R.R"}
	// {3, 4}
	// 
	// Returns: "MR"
	// 
	// The city map is 3 squares high and 6 squares wide. There are 3 'M' signs and 4 'R' signs on the map. The legend summary states that there are three POIs of type 0 and four POIs of type 1 on the map. Obviously, the former are denoted with 'M' on the map and the latter are denoted with 'R'.
	// 
	// 1)
	// {"XXXXXXXZXYYY"}
	// {1, 8, 3}
	// 
	// Returns: "ZXY"
	// 
	// There is a single 'Z' on the map, thus the legend should state that POIs of type 0 are denoted with 'Z'. There are three 'Y's on the map, therefore POIs of type 2 are surely denoted with 'Y'. Finally, it's now obvious that 'X's stand for the POIs of type 1.
	// 
	// 2)
	// {"...........",
	//  "...........",
	//  "...........",
	//  "..........T"}
	// {1}
	// 
	// Returns: "T"
	// 
	// The poor city has only one point of interest in the farmost corner.
	// 
	// 3)
	// {"AIAAARRI.......GOAI.",
	//  ".O..AIIGI.OAAAGI.A.I",
	//  ".A.IAAAARI..AI.AAGR.",
	//  "....IAI..AOIGA.GAIA.",
	//  "I.AIIIAG...GAR.IIAGA",
	//  "IA.AOA....I....I.GAA",
	//  "IOIGRAAAO.AI.AA.RAAA",
	//  "AI.AAA.AIR.AGRIAAG..",
	//  "AAAAIAAAI...AAG.RGRA",
	//  ".J.IA...G.A.AA.II.AA"}
	// 
	// {16,7,1,35,11,66}
	// 
	// 
	// Returns: "GOJIRA"
	// 
	// 
	// 
	// END KAWIGIEDIT TESTING
}
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
