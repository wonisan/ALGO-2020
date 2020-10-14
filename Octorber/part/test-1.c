#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void element(int *x,int coat);

int main()
{
    int coat;
    printf("乱数の個数＞");
    scanf("%d",&coat);
    int y[coat];

    element(y,coat);
}

void element(int *x,int coat) {
 /*Source: https://www.jpcert.or.jp/sc-rules/c-msc30-c.html
   *MSC30-C. 疑似乱数の生成に rand() 関数を使用しない。
   *これを改変したものである。
   *
   * id は、文字列 "ID" ではじまり
   * ランダムな整数が続く識別子を格納する
   */

  /* 鳥頭なので意味を記す。
   * r = ランダムな値(一時的な箱)
   * max = 乱数の上限値
   * min = 乱数の下限値
   * coat = 乱数の個数
   * cnt = 乱数を生成した数
   * x[] = ランダム値のコンテナ
   * 構造体は、時刻取得→PRNGのシード指定
   */


  enum { len = 12 };

  char id[len];
  int r;    /* ランダムな値 */
  int max;
  int min;
  int cnt = 0;
  printf("乱数の上限値＞");
  scanf("%d",&max);
  printf("乱数の下限値＞");
  scanf("%d",&min); 

 while(coat>cnt){
    /* ... */
    struct timespec ts;
        if (timespec_get(&ts, TIME_UTC) == 0) {
            printf("Cannot get time!!\n ");/* エラー処理 */
        }
        srandom(ts.tv_nsec ^ ts.tv_sec);  /* PRNG にシードを設定する */
        /* ... */
        r = (random() % (max - min + 1)) + min;  /* 乱数を生成する */
        printf("%d\n",r);
        x[cnt] = r;
        cnt = cnt + 1;
    }
}