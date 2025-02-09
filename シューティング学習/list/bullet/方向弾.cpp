#include <math.h>

void InitDirectedBullet(
	float ex, float ey,    // 敵の座標
	float& x, float& y,    // 弾の座標
	float& vx, float& vy,  // 弾の速度
	float speed,           // 弾の速さ
	float theta            // 発射角度
) {
	// 弾の座標を設定する
	x=ex; y=ey;

	// 速さspeedで角度thetaの方向に飛ぶ弾の速度(vx,vy)を求める：
	// M_PIは円周率。
	vx=cos(M_PI/180*theta)*speed;
	vy=sin(M_PI/180*theta)*speed;
}

void MoveDirectedBullet(
	float& x, float& y,  // 弾の座標
	float vx, float vy   // 弾の速度
) {
	// 弾の座標(x,y)に速度(vx,vy)を加える
	x+=vx;
	y+=vy;
}

