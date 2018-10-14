#include <cpp/lang/Integer.h>
#include <cpp/lang/String.h>
#include <cpp/lang/Array.h>
#include <stdio.h>

void testInteger()
{
	Integer n = 30;
	Integer m = n + 1;
	printf("  Value is %d\n", (int)m);
}
void testString()
{
	String s = "    (The quick brown \"Fox\" jumps over the lazy \"Dog\")  ";
    printf("Length: %u\n", s.length);
	// test copy constructor
	const char* t = s.toCharArray();
	printf("Origin Text:   '%s'\n", s.toCharArray());
	printf("toLowerCase:   '%s'\n", s.toLowerCase().toCharArray());
	printf("toUpperCase:   '%s'\n", s.toUpperCase().toCharArray());
	printf("Trim   Text:   '%s'\n", s.trim().toCharArray());
    printf("Origin Text:   '%s'\n", s.toCharArray());

    printf("\n");
    // Test polymorphism
    Object& o = s;
    printf("Object String:   %s\n", o.getName().toCharArray());


    // Test equals
    String s1 = "aa";
    String s2 = "ab";
    printf("s1.hasCode() = %ul\n", s1.hashCode());
    printf("s2.hasCode() = %ul\n", s2.hashCode());
    printf("s1.hasCode() == s2.hashCode() ? %d\n", s1.hashCode() == s2.hashCode());
    printf("s1 == s2 ? %d\n", s1.equals(s2));



	uint32 nh = s.indexOf("over");
	printf("Index Of 'over': %ul\n", nh);
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
