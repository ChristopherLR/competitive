import java.io.*;
import java.util.*;

public class Main {
	public static ArrayList <String> wordList = new ArrayList <String> ();
	public static Map <Character,Integer> alphabetNum = new LinkedHashMap<Character, Integer>();
	public static Map <Integer, Character> numAlphabet = new LinkedHashMap< Integer,Character>();
	public static ArrayList <Integer> wordNum = new ArrayList<Integer>();

	public static String alphabetStr = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	public static void main(String [] args){
		Scanner in = new Scanner(new InputStreamReader(System.in));
		int maxScore = 0;
		int diff = 0;
		String finalWord = "";
		for (int i = 0; i<alphabetStr.length(); i++){
			alphabetNum.put(alphabetStr.charAt(i),i);
			numAlphabet.put(i,alphabetStr.charAt(i));
		}
		while(in.hasNext()){
			wordList.add(in.nextLine());
		}

		String word = wordList.get(wordList.size()-1);

		for (int l = 0; l< word.length();l++){
			wordNum.add(alphabetNum.get(word.charAt(l)));
		}
		for (int i = 0; i < alphabetStr.length(); i++){
			ArrayList <Character> newWord = new ArrayList<Character>();
			String testWord = "";
			int score = 0;
			for (int x = 0; x < word.length(); x ++){
				newWord.add(numAlphabet.get((wordNum.get(x)+i)%27));
			}
			for(Character c : newWord){
				testWord = testWord + c;
			}
			for (String s : wordList){
				if (testWord.contains(s)){
					score++;
				}
			}
			if (score > maxScore){
				maxScore = score;
				finalWord = testWord;
			}

		}
		String [] wordSplit = finalWord.split(" ");
		int charNum = wordSplit[0].length();
		System.out.print(wordSplit[0]);
		for (int i = 1; i<wordSplit.length; i++){
			charNum += wordSplit[i].length() + 1;
			if (charNum > 60){
				System.out.print("\n");
				System.out.print(wordSplit[i]);
				charNum = wordSplit[i].length();
			} else {
				System.out.print(" ");
				System.out.print(wordSplit[i]);
			}
		}
		System.out.print("\n");
	}

}
