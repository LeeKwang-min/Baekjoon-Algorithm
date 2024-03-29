/*
拙失切 : 戚韻肯
析獣 : 2021.06.08
薦鯉 : 9251 - LCS
熱戚 : LCS (Logest Common Subsequence) 庚薦戚陥.
	   LCS澗 滴惟 2亜走亜 赤澗巨 原走厳 S亜 'Subsequence'戚劃 'Substring'戚劃稽 蟹感陥.
	   戚 庚薦澗 尻紗馬走 省澗 採歳 庚切伸聖 姥馬澗 庚薦戚陥.
	   (Subsequence : 尻紗馬走 省澗 採歳 庚切伸 姥馬奄)
	   (Substring : 尻紗馬澗 採歳 庚切伸 姥馬奄) ---> 5582腰 庚薦 溌昔

	   LCS澗 政誤馬奄亀 馬壱 企採歳税 庚切伸 庚薦亜 戚 硝壱軒葬拭辞 郊餓嬢 蟹神澗 井酔亜 弦陥壱 廃陥.
	   DP[n][m] = 庚切伸 A税 n腰属, B税 m腰属 庚切研 紫遂馬心聖 凶 LCS税 掩戚

	   是 繊鉢縦聖 亜走壱 坦軒研 拝 凶 2亜走 井酔稽 蟹感陥.
	   1. A[i]人 B[j]亜 旭聖 凶
	   2. A[i]人 B[j]亜 旭走 省聖 凶

	   砧 庚切亜 旭陥檎 戚澗 採歳 庚切伸税 析採亜 鞠奄 凶庚拭
	   けけけけ i
	   けけけけ j 拭辞 
	   A[i]人 B[j]税 戚穿 聡 A[i-1]引 B[j-1]猿走税 LCS研 亜走壱 赤澗 DP[i-1][j-1] 葵拭辞 +1聖 背爽檎 吉陥.

	   馬走幻, 砧 庚切亜 旭走 省陥檎 護亜走研 持唖背左焼醤 廃陥.
	   A税 i腰属研 紫遂廃 井酔人 B税 j腰属研 紫遂廃 井酔稽 蟹患惟 吉陥.
	   1. A[i]研 匂敗廃 LCS亜 亜管拝 依戚壱
	   2. B[j]研 匂敗廃 LCS亜 亜管拝 依戚陥.

	   1腰税 井酔 A[i]研 匂敗馬惟 鞠檎 B澗 B[j-1]猿走税 庚切伸戚 吃 依戚悟
	   2腰税 井酔 B[j]研 匂敗馬惟 鞠檎 A澗 A[i-1]猿走税 庚切伸戚 吃 依戚陥.

	   戚研 陥獣 妊薄馬檎
	   DP[i][j-1]引 DP[i-1][j]研 搾嘘馬惟 鞠澗 依戚陥. 戚 掻拭辞 亜舌 延 依聖 茨虞醤 馬奄 凶庚拭
	   砧 葵掻 笛 葵聖 壱牽檎 吉陥.

	   けけけ け  i
	   けけけ j-1

	   けけけ i-1
	   けけけ け  j


	   『 蓄亜 : 旭走 省精 井酔澗 因拷聖 隔嬢 溌昔馬澗 依引 旭陥.
	   D[i-1][j]蟹 D[i][j-1]拭 因拷聖 辰趨隔嬢 益 葵聖 益企稽 亜閃神澗依引 旭陥.
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int d[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans;
}