#include<stdio.h>
#include<math.h>
#define pi 3.14
void main()
{

	int i, n, shaft, kandb, shaftyt, kandbyt, flange, flangeut, dnew;
    int d_h, l_h, D, t, t_1, d_r, D_o, c, r, f, N, d_1, b, h, l;
    int k[32]={5,6,8,10,12,14,16,18,20,22,25,28,30,32,35,40,45,50,55,60,65,70,75,80,90,100,110,120,140,160,180,200};    //shaft diameter array
	float Power, shaftf, kandbf, flangef, shaftsy, shearshaft, kandbsy, shearkandb, crushingkandb;
	float crushingstresskandb, flangesu, shearflange, servicefactor, designtorque, dshaft, dnewshaft;
	float a, J, hubshear, shear_stress_flange, depth, shear_key, comp_key, d_b, comp_stress;

    system("color 70");
	printf("\nEnter the value of Power (KW) : ");
	scanf("%f",&Power);

	printf("\nEnter the rpm (n) : ");
	scanf("%d",&n);

	printf("\nMaterial of shaft that are available is: \n\t\t\t\t\t1) 40C8 (Carbon Steel (0.40%% carbon)) \n\t\t\t\t\t2) 30C8 (Carbon Steel (0.30%% carbon)) \n\t\t\t\t\t3) 35C8 (Carbon Steel (0.35%% carbon))\n");     //shaft material selection
	printf("\nEnter the serial no for shaft material : ");
	scanf("%d",&shaft);

	switch(shaft)
	{
		case 1:
			printf("\nYield Tensile strength of 40C8 shaft is 380 M-pa");
            shaftyt=380;
			break;
		case 2:
			printf("\nYield Tensile strength of 30C8 shaft is 400 M-pa");
			shaftyt=400;
			break;
		case 3:
			printf("\nYield Tensile strength of 35C8 shaft is 390 M-pa");
			shaftyt=390;
			break;
		default:
			printf("Default yield tensile strength is of 40C8 is 380 M-pa");
			break;
	}

        printf("\n\nEnter the safety factor for the shafts : ");
        scanf("%f",&shaftf);

        printf("\nMaterial for bolts and keys that are available is: \n\t\t\t\t\t1) 40C8 (Carbon Steel (0.40%% carbon)) \n\t\t\t\t\t2) 30C8 (Carbon Steel (0.30%% carbon)) \n\t\t\t\t\t3) 35C8 (Carbon Steel (0.35%% carbon))\n");
        //MATERIAL OF BOLTS AND KEY
        printf("\nEnter the serial no for bolt and keys material : ");
        scanf("%d",&kandb);

      switch(kandb)
      {
		case 1:
			printf("\nYield Tensile strength of40C8 key and bolts is 380 M-pa");
			kandbyt=380;
			break;
		case 2:
			printf("\nYield Tensile strength of 30C8 keys and bolts is 400 M-pa");
			kandbyt=400;
			break;
		case 3:
			printf("\nYield Tensile strength of 35C8 keys and bolts is 390 M-pa");
			kandbyt=390;
			break;
		default:
			printf("Default yield tensile strength is of 30C8 is 400 M-pa");
			break;
      }

        printf("\n\nEnter the safety factor for the key and bolts : ");
        scanf("%f",&kandbf);

        printf("\nMaterial for flange that are available is: \n\t\t\t\t\t1) FG200 (Grey Cast Iron) \n\t\t\t\t\t2) FG250 (Grey Cast Iron) \n\t\t\t\t\t3) FG300 (Grey Cast Iron)\n");    //material of flange
        printf("\nEnter the serial no for flange material : ");
        scanf("%d", &flange);

	switch(flange)
	{
		case 1:
			printf("\nUtimate Tensile strength of FG200 flange is 200 M-pa");
			flangeut=200;
			break;
		case 2:
			printf("\nUltimate Tensile strength of FG250 flange is 250 M-pa");
			flangeut=250;
			break;
		case 3:
			printf("\nUltimate Tensile strength of FG300 shaft is 300 M-pa");
			flangeut=300;
			break;
		default:
			printf("Default Ultimate tensile strength is of FG200 is 200 M-pa");
			break;
      }

      printf("\n\nEnter the safety factor for the flange : ");
      scanf("%f",&flangef);

      shaftsy = 0.5 * shaftyt;
      shearshaft = shaftsy / shaftf;
      printf("\nshear in shaft = %0.3f M-pa\n",shearshaft);

      kandbsy = 0.5 * kandbyt;
      shearkandb = kandbsy / kandbf;
      printf("\nshear in key and bolt = %0.3f M-pa\n",shearkandb);

      crushingkandb = 1.5 * kandbyt;
      crushingstresskandb = crushingkandb / kandbf;
      printf("\nCompressive stress in key and bolt = %0.3f M-pa\n",crushingstresskandb);

      flangesu = 0.5 * flangeut;
      shearflange = flangesu / flangef;
      printf("\nFlange shear = %0.3f M-pa\n",shearflange);

      printf("\n\n\t**Diameter of shafts**\n");
      printf("\n\t  --------------------  ");
      printf("\n\nEnter value of servicefactor : ");
      scanf("%f",&servicefactor);

      designtorque=((60 * 1000000 * servicefactor * Power) / (2 * pi * n));
      printf("\n\nDesign torque = %0.3f N-mm\n",designtorque);
      a=((16 * designtorque) / (3.14 * shearshaft));

        dshaft=pow(a,0.3333);
        for(i=0;i<32;i++)
        {
            if(k[i]>dshaft)
                {
                    dnew=k[i];
                    printf("\nDiameter of shaft = %d mm\n",dnew);
                    break;
                }
        }

    printf("\n\n************ Dimension of Flange Coupling are as follows ***************\n");

    d_h = (2 * dnew);
    l_h = (1.5 * dnew);
    D = (3 * dnew);
    t = (0.5 * dnew);
    t_1 = (0.25 * dnew);
    d_r = (1.5 * dnew);
    D_o = ((4 * dnew) + (2 * t_1));

    printf("\n\t\tOutside Diameter of hub (D) = %d mm\n",d_h);
    printf("\n\t\tLength of hub (L) = %d mm\n",l_h);
    printf("\n\t\tPitch Circle diameter of bolts (D1) = %d mm\n",D);
    printf("\n\t\tThickness of flange (tf) = %d mm\n",t);
    printf("\n\t\tThickness of Protecting Rim (t) = %d mm\n",t_1);
    printf("\n\t\tDiameter of Spigot and recess = %d mm\n",d_r);
    printf("\n\t\tOutside Diameter of flange (D2) = %d mm\n",D_o);

//Thickness of Recess is assumed to be 5mm.
//The Hub is treated as hollow shaft subjected to Torsional Moment.

    c = pow(d_h,4);
    b = pow(dnew,4);

    J = ((3.14 * (c-b)) / 32);
    r = d_h / 2;
    f = pow(d_h,2);

//Torsional Shear Stress is hub.
    hubshear = ((designtorque * r) / J);

    if(hubshear<shearflange)
    {
        printf("\nDesign of Hub Diameter is safe...\n");
    }
    else
    {
        printf("\n try again!!\n");
    }

//shear stress in the flange at the junction of hub.
    shear_stress_flange = ((2 * designtorque) / (3.14 * f*t));

    if(shear_stress_flange < shearflange)
    {
        printf("\nStresses in the flange are within permissible limits...\n");
    }
    else
    {
        printf("\n try again!!\n");
    }

    if(dnew<=40)
    {
        N=3;
        printf("\n\t\tNo of Bolts (N) = 3,  (as shaft diameter <= 40 mm)\n");
    }
    else if(40<dnew<=100)
    {
        N=4;
        printf("\n\t\tNo of Bolts (N) = 4,    (as shaft diameter 40 mm < d <= 100 mm)\n");
    }
    else if(100<dnew<180)
    {
        N=6;
        printf("\n\t\tNo of Bolts (N) = 6,    (as shaft diameter 100 mm < d <= 180 mm)\n");
    }

//Diameter of bolt
    d_b = ((8 * designtorque) / (3.14 * D * N * shearkandb));
    d_b = sqrt(d_b);
    d_1 = ceil(d_b);
    printf("\n\t\tDiameter of Bolts (d1) = %d mm\n",d_1);

//compressive stress in bolt is determined.
    comp_stress=((2 * designtorque) / (3.14 * d_1 * t * D * N));

    if(comp_stress<crushingstresskandb)
    {
        printf("\nIt is safe as it is within permissible limit of compressive stress...\n");
    }
    else
    {
        printf("\n try again!!\n");
    }

    if(6<dnew && dnew<=8)
    {
        b=2;
        h=2;
        depth=1.2;
    }
    else if(8<dnew && dnew<=10)
    {
        b=3;
        h=3;
        depth=1.8;
    }
    else if(10<dnew && dnew<=12)
    {
        b=4;
        h=4;
        depth=2.5;
    }
    else if(12<dnew && dnew<=17)
    {
        b=5;
        h=5;
        depth=3;
    }
    else if(17<dnew && dnew<=22)
    {
        b=6;
        h=6;
        depth=3.5;
    }
    else if(22<dnew && dnew<=30)
    {
        b=8;
        h=7;
        depth=4;
    }
    else if(30<dnew && dnew<=38)
    {
        b=10;
        h=8;
        depth=5;
    }
    else if(38<dnew && dnew<=44)
    {
        b=12;
        h=8;
        depth=5;
    }
    else if(44<dnew && dnew<=50)
    {
        b=14;
        h=9;
        depth=5.5;
    }
    else if(50<dnew && dnew<=58)
    {
        b=16;
        h=10;
        depth=6;
    }
    else if(58<dnew && dnew<=65)
    {
        b=18;
        h=11;
        depth=7;
    }
    else if(65<dnew && dnew<=75)
    {
        b=20;
        h=12;
        depth=7.5;
    }
    else if(75<dnew && dnew<=85)
    {
        b=22;
        h=14;
        depth=9;
    }
    else if(85<dnew && dnew<=95)
    {
        b=25;
        h=14;
        depth=9;
    }
    else if(95<dnew && dnew<=110)
    {
        b=28;
        h=16;
        depth=10;
    }
    else if(110<dnew && dnew<=130)
    {
        b=32;
        h=18;
        depth=11;
    }
    else if(130<dnew && dnew<=150)
    {
        b=36;
        h=20;
        depth=12;
    }
    else if(150<dnew && dnew<=170)
    {
        b=40;
        h=22;
        depth=13;
    }
    else if(170<dnew && dnew<=200)
    {
        b=45;
        h=25;
        depth=15;
    }
    //The length of the key is equal to hub diameter.
    l=l_h;

    printf("\n\t\tLength of Key (L) = %d mm",l);
    printf("\n\n\t\tBreadth of Key (b) = %d mm",b);
    printf("\n\n\t\tHeight of Key (h) = %d mm",h);

    shear_key=((2* designtorque)/(dnew * b * l));

    if (shear_key < shearkandb)
    {
        printf("\n\nShear stress induced in key is within Permissible limit...");
    }

    comp_key=((4 * designtorque) / (dnew * h * l));

    if(comp_key < crushingstresskandb)
    {
        printf("\n\nCompressive stress induced in key is within Permissible limit...");
    }
    printf("\n\n\n\n");

}
