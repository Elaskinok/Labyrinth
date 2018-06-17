#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int securitedEnter(int left_barricade, int right_barricade) {
	int flag;
	int answer;
	do {
		flag = scanf("%d", &answer);
		rewind(stdin);
	} while (!flag || (answer < left_barricade || answer > right_barricade));
	puts("");
	return answer;
}

//int securitedEnter(int left_barricade, int right_barricade) {
//	int result = {};
//	std::cin >> result;
//}