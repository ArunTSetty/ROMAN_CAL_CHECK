#include <check.h>
#include "implementation.h"
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<check.h>
#define MAX 4096



START_TEST(ONEplusONE)
{	
	char ostring1[MAX] = "I";
	char ostring2[MAX] = "I";
	ck_assert_str_eq(add(ostring1,ostring2), "II");
	

	
}
END_TEST

START_TEST(ONEplusTWO)
{	
	char ostring1[MAX] = "I";
	char ostring2[MAX] = "II";
	ck_assert_str_eq(add(ostring1,ostring2), "III");
	

	
}
END_TEST

START_TEST(TWOplusTWO)
{	
	char ostring1[MAX] = "II";
	char ostring2[MAX] = "II";
	ck_assert_str_eq(add(ostring1,ostring2), "IV");
	

	
}
END_TEST

START_TEST(FOURplusFIVE)
{	
	char ostring1[MAX] = "IV";
	char ostring2[MAX] = "V";
	ck_assert_str_eq(add(ostring1,ostring2), "IX");
	

	
}
END_TEST

START_TEST(FIFTYplusFIFTY)
{	
	char ostring1[MAX] = "L";
	char ostring2[MAX] = "L";
	ck_assert_str_eq(add(ostring1,ostring2), "C");
	

	
}
END_TEST

START_TEST(TWOHUNDREDFIFTYplusTWOHUNDREDFIFTY)
{	
	char ostring1[MAX] = "CCL";
	char ostring2[MAX] = "CCL";
	ck_assert_str_eq(add(ostring1,ostring2), "D");
	

	
}
END_TEST

START_TEST(FIVEHUNDREDONEplusFOURHUNDREDNINETYNINE)
{
	char ostring1[MAX] = "DI";
	char ostring2[MAX] = "CDXCIX";
	ck_assert_str_eq(add(ostring1,ostring2), "M");
	

	
}
END_TEST

START_TEST(ONETHOUSANDONEHUNDREDplusFOURHUNDREDNINETYNINE)
{
	char ostring1[MAX] = "MC";
	char ostring2[MAX] = "CDXCIX";
	ck_assert_str_eq(add(ostring1,ostring2), "MDXCIX");
	

	
}
END_TEST

Suite * roman_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, ONEplusONE);
    tcase_add_test(tc_core, ONEplusTWO);
    tcase_add_test(tc_core, TWOplusTWO);
    tcase_add_test(tc_core, FOURplusFIVE);
    tcase_add_test(tc_core, FIFTYplusFIFTY);
    tcase_add_test(tc_core, TWOHUNDREDFIFTYplusTWOHUNDREDFIFTY);
    tcase_add_test(tc_core, FIVEHUNDREDONEplusFOURHUNDREDNINETYNINE);	
    tcase_add_test(tc_core, ONETHOUSANDONEHUNDREDplusFOURHUNDREDNINETYNINE);			
    suite_add_tcase(s, tc_core);

    return s;
}

 int main(void)
 {

    int number_failed;
    Suite *s;
    SRunner *sr;
	
    s = roman_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
