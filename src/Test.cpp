#include <cpp/lang/Integer.h>
#include <cpp/lang/String.h>
#include <cpp/lang/Array.h>
#include <stdio.h>

#include "utils/Debug.h"

void testInteger()
{
	Integer n = 30;
	Integer m = n + 1;
	Debug::log("  Value is %d\n", (int)m);
}
void testString()
{
	String s = "    (The quick brown \"Fox\" jumps over the lazy \"Dog\")  ";
    Debug::log("Length: %u", s.length);
	// test copy constructor
	const char* t = s.toCharArray();
	Debug::log("Origin Text:   '%s'", s.toCharArray());
	Debug::log("toLowerCase:   '%s'", s.toLowerCase().toCharArray());
	Debug::log("toUpperCase:   '%s'", s.toUpperCase().toCharArray());
	Debug::log("Trim   Text:   '%s'", s.trim().toCharArray());
    Debug::log("Origin Text:   '%s'", s.toCharArray());

    Debug::log("");
    // Test polymorphism
    Object& o = s;
    Debug::log("Object String:   %s", o.getName().toCharArray());


    // Test equals
    String s1 = "aa";
    String s2 = "ab";
    Debug::log("s1.hasCode() = %ul", s1.hashCode());
    Debug::log("s2.hasCode() = %ul", s2.hashCode());
    Debug::log("s1.hasCode() == s2.hashCode() ? %d", s1.hashCode() == s2.hashCode());
    Debug::log("s1 == s2 ? %d", s1.equals(s2));



	uint32 nh = s.indexOf("over");
	Debug::log("Index Of 'over': %ul", nh);
}

void testArray()
{
	Array<int> a = { 1, 2, 4, 7, 8, 9, 0 };
	a.length;
	int y = a[3];
	a.push(1234);
	int last = a[a.length - 1];
	int d = a.pop();
	int length = a.length;
	int c = 0;
}

int main()
{
	testString();
	int a = 0;
}
