/*
拙失切 : 戚雌呪
析獣 : 2021.02.16
薦鯉 : 砺闘稽耕葛 - 14500
熱戚 : 崎欠闘匂什戚檎辞 姥薄径聖 左澗 庚薦
       置企 500 * 500牒拭辞 恥 井酔税 呪 19亜走研 伊紫馬澗 庚薦戚奄 凶庚拭
	   崎欠闘 匂什稽 乞窮 井酔税呪研 溌昔馬檎 鞠澗 娃舘廃 庚薦戚陥.

	   陥幻... 畳短蟹惟 葛亜陥研 背醤 廃陥...
	   (益顕 益軒壱 疎妊 旋嬢砧壱 姥薄馬檎 襲陥)
*/
#include<iostream>
#include<algorithm>

using namespace std;

int point[501][501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> point[i][j];
		}
	}

	int totalPoint = 0;
	// けけけけ 亜稽
	for (int i = 0; i < n; i++) { // 亜稽
		for (int j = 0; j < m - 3; j++) { // 室稽
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i][j + 3];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// けけけけ 室稽
	for (int i = 0; i < n - 3; i++) {
		for (int j = 0; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 3][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// けけ
	// けけ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i][j + 1] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// け
	// け
	// けけ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   け
	//   け
	// けけ
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 2][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// けけ
	//   け
	//   け
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j + 1] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// けけ
	// け
	// け
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j] + point[i + 2][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// けけけ
	//     け
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// けけけ
	// け
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i][j + 2] + point[i + 1][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//     け
	// けけけ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 2; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j - 1] + point[i + 1][j - 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// け
	// けけけ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j + 1] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   け
	// けけ
	//   け
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 1][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// け
	// けけ
	// け
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 2][j] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   け
	// けけけ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j - 1] + point[i + 1][j] + point[i + 1][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// けけけ
	//   け
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j - 1] + point[i + 1][j] + point[i][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// け
	// けけ
	//   け
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j + 1] + point[i + 2][j + 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   け
	// けけ
	// け
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < m; j++) {
			int nowPoint = point[i][j] + point[i + 1][j] + point[i + 1][j - 1] + point[i + 2][j - 1];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	// けけ
	//   けけ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 2; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j + 1] + point[i + 1][j + 2];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	//   けけ
	// けけ
	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			int nowPoint = point[i][j] + point[i][j + 1] + point[i + 1][j - 1] + point[i + 1][j];
			totalPoint = max(totalPoint, nowPoint);
		}
	}

	cout << totalPoint;
}