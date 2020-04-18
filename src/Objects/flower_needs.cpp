#include "flower_needs.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	static const int chargerSpeed=20;
	static const int degreeSpeed=10;
	static const int maxCharge=100;
	static float needsTimer=0;
	static const float maxNeedsTimer=1.5f;

	static const int recsWidth=83;
	static const int recsHeight=12;
	static const int recsY=243;
	static const int sunRecX=404;
	static const int waterRecX=46;

	enum FlowerNeed{
		sun,
		water,
		nothing
	};

	FlowerNeed needs;

	Flower_Needs::Flower_Needs(){
		_sunSprite=sunSprite;
		_waterSprite=waterSprite;
		_needSunSprite=needSunSprite;
		_needWaterSprite=needWaterSprite;
		needs=nothing;
		_charging=false;
		_sunCharge=33;
		_waterCharge=33;

		_sunChargeRec.x=sunRecX;
		_sunChargeRec.y=recsY;
		_sunChargeRec.width=recsWidth;
		_sunChargeRec.height=recsHeight;

		_waterChargeRec.x=waterRecX;
		_waterChargeRec.y=recsY;
		_waterChargeRec.width=recsWidth;
		_waterChargeRec.height=recsHeight;
	}
	Flower_Needs::~Flower_Needs(){

	}
	void Flower_Needs::input(){
		if(IsKeyDown(KEY_LEFT)){
			_charging=true;
			if(needs!=water){
				_waterCharge+=chargerSpeed*GetFrameTime();
				if(_waterCharge>=maxCharge)
					_waterCharge=maxCharge;

				_sunCharge-=degreeSpeed*GetFrameTime();
			}
			else if(needs==water){
				_waterCharge+=chargerSpeed*2*GetFrameTime();
				if(_waterCharge>=maxCharge)
					_waterCharge=maxCharge;
			}
		}
		else if(IsKeyDown(KEY_RIGHT)){
			_charging=true;
			if(needs!=sun){
				_sunCharge+=chargerSpeed*GetFrameTime();
				if(_sunCharge>=maxCharge)
					_sunCharge=maxCharge;

				_waterCharge-=degreeSpeed*GetFrameTime();
			}
			else if(needs==sun){
				_sunCharge+=chargerSpeed*2*GetFrameTime();
				if(_sunCharge>=maxCharge)
					_sunCharge=maxCharge;
			}
		}
		else
			_charging=false;
	}
	void Flower_Needs::update(){
		if(_charging==false){
			_sunCharge-=chargerSpeed*GetFrameTime();
			_waterCharge-=chargerSpeed*GetFrameTime();

		}

		if(_sunCharge<=0){
			_sunCharge=0;
			final=lose;
			flowerState=dead;
		}
		if(_waterCharge<=0){
			_waterCharge=0;
			final=lose;
			flowerState=dead;
		}

		needsTimer+=GetFrameTime();
		if(needsTimer>=maxNeedsTimer){
			needsTimer=0;
			int need=GetRandomValue(1,4);
			if(need==1)
				needs=sun;
			else if(need==2)
				needs=water;
			else
				needs=nothing;
		}
	}
	void Flower_Needs::draw(){
		_sunChargeRec.width=(recsWidth*_sunCharge)/100;
		_waterChargeRec.width=(recsWidth*_waterCharge)/100;
		DrawRectangleRec(_sunChargeRec,YELLOW);
		DrawRectangleRec(_waterChargeRec,BLUE);
		
		DrawTexture(_sunSprite,0,0,WHITE);
		DrawTexture(_waterSprite,0,0,WHITE);

		if(needs==sun)
			DrawTexture(_needSunSprite,0,0,WHITE);
		else if(needs==water)
			DrawTexture(_needWaterSprite,0,0,WHITE);
	}
	bool Flower_Needs::getNeedSun(){
		if(needs==sun)
			return true;
		return false;
	}
	bool Flower_Needs::getNeedWater(){
		if(needs==water)
			return true;
		return false;
	}
	float Flower_Needs::getSunCharge(){
		return _sunCharge;
	}
	float Flower_Needs::getWaterCharge(){
		return _waterCharge;
	}
}