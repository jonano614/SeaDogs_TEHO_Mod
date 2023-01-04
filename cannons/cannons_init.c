void InitBaseCannons_CalcSpeedV0(ref rCannon, float fFireRange)
{
	rCannon.FireRange = fFireRange;
	rCannon.SpeedV0 = sqrt(fFireRange * 9.81 / sin( 2.0 * MakeFloat(rCannon.FireAngMax)) );
}

void InitCannons()
{
	ref rCannon;
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS3]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber3";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_3";
	rCannon.caliber = 3;
	rCannon.ReloadTime = 10;
	rCannon.Cost = 105;
	rCannon.Weight = 3;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 1.0;
	rCannon.hp = 20.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,350.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS6]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber6";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_6";
	rCannon.caliber = 6;
	rCannon.ReloadTime = 19;
	rCannon.Cost = 215;
	rCannon.Weight = 6;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 1.5;
	rCannon.hp = 45.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,450.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS12]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber12";
	rCannon.picture = "cannons5";
	rCannon.Sound = "cannon_fire_cannon_12";
	rCannon.caliber = 12;
	rCannon.ReloadTime = 31;
	rCannon.Cost = 425;
	rCannon.Weight = 11;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 2.0;
	rCannon.hp = 79.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,550.0);

	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS16]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber16";
	rCannon.picture = "cannons6";
	rCannon.Sound = "cannon_fire_cannon_16";
	rCannon.caliber = 16;
	rCannon.ReloadTime = 40;
	rCannon.Cost = 600;
	rCannon.Weight = 16;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 2.5;
	rCannon.hp = 76.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,600.0);
		
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS20]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber20";
	rCannon.picture = "cannons7";
	rCannon.Sound = "cannon_fire_cannon_20";
	rCannon.caliber = 20;
	rCannon.ReloadTime = 48;
	rCannon.Weight = 20;
	rCannon.Cost = 815;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 3.0;
	rCannon.hp = 73.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,650.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS24]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.name = "caliber24";
	rCannon.picture = "cannons7";
	rCannon.Sound = "cannon_fire_cannon_24";
	rCannon.caliber = 24;
	rCannon.ReloadTime = 56;
	rCannon.Weight = 29;
	rCannon.Cost = 1200;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 4.0;
	rCannon.hp = 70.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,700.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS32]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 32;
	rCannon.name = "caliber32";
	rCannon.picture = "cannons8";
	rCannon.Sound = "cannon_fire_cannon_32";
	rCannon.ReloadTime = 61;
	rCannon.Cost = 1705;
	rCannon.Weight = 40;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 5.0;
	rCannon.hp = 65.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,650.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS36]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 36;
	rCannon.name = "caliber36";
	rCannon.picture = "cannons8";
	rCannon.Sound = "cannon_fire_cannon_36";
	rCannon.ReloadTime = 63;
	rCannon.Cost = 2055;
	rCannon.Weight = 46;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 6.0;
	rCannon.TradeOff = true;
	rCannon.hp = 60.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,600.0); 
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS42]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 42;
	rCannon.name = "caliber42";
	rCannon.picture = "cannons11";
	rCannon.Sound = "cannon_fire_cannon_42";
	rCannon.ReloadTime = 65;
	rCannon.Cost = 2490;
	rCannon.Weight = 50;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 7.0;
	rCannon.TradeOff = true;
	rCannon.hp = 55.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,550.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS48]);
	rCannon.type = CANNON_NAME_CANNON;
	rCannon.caliber = 48;
	rCannon.name = "caliber48";
	rCannon.picture = "cannons12";
	rCannon.Sound = "cannon_fire_cannon_48";
	rCannon.ReloadTime = 50;
	rCannon.Cost = 21505;
	rCannon.Weight = 80;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.DamageMultiply = 10.0;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 14.0;
	rCannon.TradeOff = true;
	rCannon.hp = 80.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,1600.0);
	
    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS8]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber8";
	rCannon.picture = "cannons1";
	rCannon.Sound = "cannon_fire_culverine_8";
	rCannon.caliber = 8;
	rCannon.ReloadTime = 35;
	rCannon.Cost = 345;
	rCannon.Weight = 16;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 2.0;
	rCannon.hp = 60.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,700.0);
	
	makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS18]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.name = "caliber18";
	rCannon.picture = "cannons2";
	rCannon.Sound = "cannon_fire_culverine_18";
	rCannon.caliber = 18;
	rCannon.ReloadTime = 52;
	rCannon.Cost = 885;
	rCannon.Weight = 32;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.35;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 3.0;
	rCannon.hp = 75.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,850.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS36]);
	rCannon.type = CANNON_NAME_CULVERINE;
	rCannon.caliber = 36;
	rCannon.name = "caliber36";
	rCannon.picture = "cannons4";
	rCannon.Sound = "cannon_fire_culverine_36";
	rCannon.ReloadTime = 70;
	rCannon.Cost = 2545;
	rCannon.Weight = 50;
	rCannon.FireAngMax = 0.60;
	rCannon.FireAngMin = -0.45;
	rCannon.TimeSpeedMultiply = 1.0;
	rCannon.BigBall = 0;
	rCannon.SizeMultiply = 1.0;
	rCannon.HeightMultiply = 1.0;
	rCannon.DamageMultiply = 5.5;
	rCannon.TradeOff = true;
	rCannon.hp = 80.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,900.0);
}