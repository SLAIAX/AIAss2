#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules

void initFuzzyRules(fuzzy_system_rec *fl) {
	
   const int
      no_of_x_rules = 25,
      no_of_theta_rules = 25;
   
   int i;
	
//---------------------------------------------------------------------------- 	
//THETA vs. THETA_DOT	
//   
   for (i = 0;i < no_of_theta_rules;i++) {
       fl->rules[i].inp_index[0] = in_theta;
       fl->rules[i].inp_index[1] = in_theta_dot;
   }
      
   /* Regions for theta and theta_dot: */
   //sample only

   fl->rules[0].inp_fuzzy_set[0] = in_nl;
   fl->rules[0].inp_fuzzy_set[1] = in_nl;
   fl->rules[0].out_fuzzy_set =  out_nvl;

   fl->rules[1].inp_fuzzy_set[0] = in_nl;
   fl->rules[1].inp_fuzzy_set[1] = in_ns;
   fl->rules[1].out_fuzzy_set =  out_nvl; //test

   fl->rules[2].inp_fuzzy_set[0] = in_nl;
   fl->rules[2].inp_fuzzy_set[1] = in_ze;
   fl->rules[2].out_fuzzy_set =  out_nvl;

   fl->rules[3].inp_fuzzy_set[0] = in_nl;
   fl->rules[3].inp_fuzzy_set[1] = in_ps;
   fl->rules[3].out_fuzzy_set =  out_nvl; //ns

   fl->rules[4].inp_fuzzy_set[0] = in_nl;
   fl->rules[4].inp_fuzzy_set[1] = in_pl;
   fl->rules[4].out_fuzzy_set =  out_nl;

   fl->rules[5].inp_fuzzy_set[0] = in_ns;
   fl->rules[5].inp_fuzzy_set[1] = in_nl;
   fl->rules[5].out_fuzzy_set =  out_nvl;

   fl->rules[6].inp_fuzzy_set[0] = in_ns;
   fl->rules[6].inp_fuzzy_set[1] = in_ns;
   fl->rules[6].out_fuzzy_set =  out_nvl;

   fl->rules[7].inp_fuzzy_set[0] = in_ns;
   fl->rules[7].inp_fuzzy_set[1] = in_ze;
   fl->rules[7].out_fuzzy_set =  out_nl;

   fl->rules[8].inp_fuzzy_set[0] = in_ns;
   fl->rules[8].inp_fuzzy_set[1] = in_ps;
   fl->rules[8].out_fuzzy_set =  out_nm;

   fl->rules[9].inp_fuzzy_set[0] = in_ns;
   fl->rules[9].inp_fuzzy_set[1] = in_pl;
   fl->rules[9].out_fuzzy_set =  out_nm; //ze

   fl->rules[10].inp_fuzzy_set[0] = in_ze;
   fl->rules[10].inp_fuzzy_set[1] = in_nl;
   fl->rules[10].out_fuzzy_set =  out_nl;

   fl->rules[11].inp_fuzzy_set[0] = in_ze;
   fl->rules[11].inp_fuzzy_set[1] = in_ns;
   fl->rules[11].out_fuzzy_set =  out_nm;

   fl->rules[12].inp_fuzzy_set[0] = in_ze;
   fl->rules[12].inp_fuzzy_set[1] = in_ze;
   fl->rules[12].out_fuzzy_set =  out_ze;

   fl->rules[13].inp_fuzzy_set[0] = in_ze;
   fl->rules[13].inp_fuzzy_set[1] = in_ps;
   fl->rules[13].out_fuzzy_set =  out_pm;

   fl->rules[14].inp_fuzzy_set[0] = in_ze;
   fl->rules[14].inp_fuzzy_set[1] = in_pl;
   fl->rules[14].out_fuzzy_set =  out_pl;

   fl->rules[15].inp_fuzzy_set[0] = in_ps;
   fl->rules[15].inp_fuzzy_set[1] = in_nl;
   fl->rules[15].out_fuzzy_set =  out_ze;

   fl->rules[16].inp_fuzzy_set[0] = in_ps;
   fl->rules[16].inp_fuzzy_set[1] = in_ns;
   fl->rules[16].out_fuzzy_set =  out_pm;

   fl->rules[17].inp_fuzzy_set[0] = in_ps;
   fl->rules[17].inp_fuzzy_set[1] = in_ze;
   fl->rules[17].out_fuzzy_set =  out_pl;
   
   fl->rules[18].inp_fuzzy_set[0] = in_ps;
   fl->rules[18].inp_fuzzy_set[1] = in_ps;
   fl->rules[18].out_fuzzy_set =  out_pvl;

   fl->rules[19].inp_fuzzy_set[0] = in_ps;
   fl->rules[19].inp_fuzzy_set[1] = in_pl;
   fl->rules[19].out_fuzzy_set =  out_pvl;

   fl->rules[20].inp_fuzzy_set[0] = in_pl;
   fl->rules[20].inp_fuzzy_set[1] = in_nl;
   fl->rules[20].out_fuzzy_set =  out_pl;

   fl->rules[21].inp_fuzzy_set[0] = in_pl;
   fl->rules[21].inp_fuzzy_set[1] = in_ns;
   fl->rules[21].out_fuzzy_set =  out_pl;

   fl->rules[22].inp_fuzzy_set[0] = in_pl;
   fl->rules[22].inp_fuzzy_set[1] = in_ze;
   fl->rules[22].out_fuzzy_set =  out_pvl;

   fl->rules[23].inp_fuzzy_set[0] = in_pl;
   fl->rules[23].inp_fuzzy_set[1] = in_ps;
   fl->rules[23].out_fuzzy_set =  out_pvl;

   fl->rules[24].inp_fuzzy_set[0] = in_pl;
   fl->rules[24].inp_fuzzy_set[1] = in_pl;
   fl->rules[24].out_fuzzy_set =  out_pvl;

	
	// BELOW IS ALL ORIGINAL
//----------------------------------------------------------------------------   
//X vs. X_DOT
//
   for (i = 0;i < no_of_x_rules;i++) {
   	  fl->rules[i + no_of_theta_rules].inp_index[0] = in_x;
   	  fl->rules[i + no_of_theta_rules].inp_index[1] = in_x_dot;
	}
	  
	//Regions for x and x_dot: 
   fl->rules[no_of_theta_rules + 0].inp_fuzzy_set[0] = in_nl;
   fl->rules[no_of_theta_rules + 0].inp_fuzzy_set[1] = in_nl;
   fl->rules[no_of_theta_rules + 0].out_fuzzy_set = out_pvl;

   fl->rules[no_of_theta_rules + 1].inp_fuzzy_set[0] = in_nl;
   fl->rules[no_of_theta_rules + 1].inp_fuzzy_set[1] = in_ns;
   fl->rules[no_of_theta_rules + 1].out_fuzzy_set = out_pl;

   fl->rules[no_of_theta_rules + 2].inp_fuzzy_set[0] = in_nl;
   fl->rules[no_of_theta_rules + 2].inp_fuzzy_set[1] = in_ze;
   fl->rules[no_of_theta_rules + 2].out_fuzzy_set = out_pm;

   fl->rules[no_of_theta_rules + 3].inp_fuzzy_set[0] = in_nl;
   fl->rules[no_of_theta_rules + 3].inp_fuzzy_set[1] = in_ps;
   fl->rules[no_of_theta_rules + 3].out_fuzzy_set = out_ps;

   fl->rules[no_of_theta_rules + 4].inp_fuzzy_set[0] = in_nl;
   fl->rules[no_of_theta_rules + 4].inp_fuzzy_set[1] = in_pl;
   fl->rules[no_of_theta_rules + 4].out_fuzzy_set = out_ze;

   fl->rules[no_of_theta_rules + 5].inp_fuzzy_set[0] = in_ns;
   fl->rules[no_of_theta_rules + 5].inp_fuzzy_set[1] = in_nl;
   fl->rules[no_of_theta_rules + 5].out_fuzzy_set = out_pl;

   fl->rules[no_of_theta_rules + 6].inp_fuzzy_set[0] = in_ns;
   fl->rules[no_of_theta_rules + 6].inp_fuzzy_set[1] = in_ns;
   fl->rules[no_of_theta_rules + 6].out_fuzzy_set = out_pm;

   fl->rules[no_of_theta_rules + 7].inp_fuzzy_set[0] = in_ns;
   fl->rules[no_of_theta_rules + 7].inp_fuzzy_set[1] = in_ze;
   fl->rules[no_of_theta_rules + 7].out_fuzzy_set = out_ps;

   fl->rules[no_of_theta_rules + 8].inp_fuzzy_set[0] = in_ns;
   fl->rules[no_of_theta_rules + 8].inp_fuzzy_set[1] = in_ps;
   fl->rules[no_of_theta_rules + 8].out_fuzzy_set = out_ze;

   fl->rules[no_of_theta_rules + 9].inp_fuzzy_set[0] = in_ns;
   fl->rules[no_of_theta_rules + 9].inp_fuzzy_set[1] = in_pl;
   fl->rules[no_of_theta_rules + 9].out_fuzzy_set = out_ns;

   fl->rules[no_of_theta_rules + 10].inp_fuzzy_set[0] = in_ze;
   fl->rules[no_of_theta_rules + 10].inp_fuzzy_set[1] = in_nl;
   fl->rules[no_of_theta_rules + 10].out_fuzzy_set = out_pm;

   fl->rules[no_of_theta_rules + 11].inp_fuzzy_set[0] = in_ze;
   fl->rules[no_of_theta_rules + 11].inp_fuzzy_set[1] = in_ns;
   fl->rules[no_of_theta_rules + 11].out_fuzzy_set = out_ps;

   fl->rules[no_of_theta_rules + 12].inp_fuzzy_set[0] = in_ze;
   fl->rules[no_of_theta_rules + 12].inp_fuzzy_set[1] = in_ze;
   fl->rules[no_of_theta_rules + 12].out_fuzzy_set = out_ze;

   fl->rules[no_of_theta_rules + 13].inp_fuzzy_set[0] = in_ze;
   fl->rules[no_of_theta_rules + 13].inp_fuzzy_set[1] = in_ps;
   fl->rules[no_of_theta_rules + 13].out_fuzzy_set = out_ns;

   fl->rules[no_of_theta_rules + 14].inp_fuzzy_set[0] = in_ze;
   fl->rules[no_of_theta_rules + 14].inp_fuzzy_set[1] = in_pl;
   fl->rules[no_of_theta_rules + 14].out_fuzzy_set = out_nm;

   fl->rules[no_of_theta_rules + 15].inp_fuzzy_set[0] = in_ps;
   fl->rules[no_of_theta_rules + 15].inp_fuzzy_set[1] = in_nl;
   fl->rules[no_of_theta_rules + 15].out_fuzzy_set = out_ps;

   fl->rules[no_of_theta_rules + 16].inp_fuzzy_set[0] = in_ps;
   fl->rules[no_of_theta_rules + 16].inp_fuzzy_set[1] = in_ns;
   fl->rules[no_of_theta_rules + 16].out_fuzzy_set = out_ze;

   fl->rules[no_of_theta_rules + 17].inp_fuzzy_set[0] = in_ps;
   fl->rules[no_of_theta_rules + 17].inp_fuzzy_set[1] = in_ze;
   fl->rules[no_of_theta_rules + 17].out_fuzzy_set = out_ns;

   fl->rules[no_of_theta_rules + 18].inp_fuzzy_set[0] = in_ps;
   fl->rules[no_of_theta_rules + 18].inp_fuzzy_set[1] = in_ps;
   fl->rules[no_of_theta_rules + 18].out_fuzzy_set = out_nm;

   fl->rules[no_of_theta_rules + 19].inp_fuzzy_set[0] = in_ps;
   fl->rules[no_of_theta_rules + 19].inp_fuzzy_set[1] = in_pl;
   fl->rules[no_of_theta_rules + 19].out_fuzzy_set = out_nl;

   fl->rules[no_of_theta_rules + 20].inp_fuzzy_set[0] = in_pl;
   fl->rules[no_of_theta_rules + 20].inp_fuzzy_set[1] = in_nl;
   fl->rules[no_of_theta_rules + 20].out_fuzzy_set = out_ze;

   fl->rules[no_of_theta_rules + 21].inp_fuzzy_set[0] = in_pl;
   fl->rules[no_of_theta_rules + 21].inp_fuzzy_set[1] = in_ns;
   fl->rules[no_of_theta_rules + 21].out_fuzzy_set = out_ns;

   fl->rules[no_of_theta_rules + 22].inp_fuzzy_set[0] = in_pl;
   fl->rules[no_of_theta_rules + 22].inp_fuzzy_set[1] = in_ze;
   fl->rules[no_of_theta_rules + 22].out_fuzzy_set = out_nm;

   fl->rules[no_of_theta_rules + 23].inp_fuzzy_set[0] = in_pl;
   fl->rules[no_of_theta_rules + 23].inp_fuzzy_set[1] = in_ps;
   fl->rules[no_of_theta_rules + 23].out_fuzzy_set = out_nl;

   fl->rules[no_of_theta_rules + 24].inp_fuzzy_set[0] = in_pl;
   fl->rules[no_of_theta_rules + 24].inp_fuzzy_set[1] = in_pl;
   fl->rules[no_of_theta_rules + 24].out_fuzzy_set = out_nvl;

   // OUr code

   return;
}


void initMembershipFunctions(fuzzy_system_rec *fl) {
	
   /* The X membership functions */

   //Sample routines only, to give you an idea of what to do here
   fl->inp_mem_fns[in_x][in_nl] = init_trapz(-2, -1.7, 0, 0, left_trapezoid);
   fl->inp_mem_fns[in_x][in_ns] = init_trapz(-2, -1.7, -1, -0.7, regular_trapezoid);
   fl->inp_mem_fns[in_x][in_ze] = init_trapz(-1, -0.7, 0.7, 0.1, regular_trapezoid);
   fl->inp_mem_fns[in_x][in_ps] = init_trapz(0.7, 1, 1.7, 2, regular_trapezoid);
   fl->inp_mem_fns[in_x][in_pl] = init_trapz(1.7, 2, 0, 0, right_trapezoid);
	
   /* The X dot membership functions */
   //enter the appropriate membership function initialisations here 

   fl->inp_mem_fns[in_x_dot][in_nl] = init_trapz(-2.8, -1.7, 0, 0, left_trapezoid);
   fl->inp_mem_fns[in_x_dot][in_ns] = init_trapz(-2.8, -1.7, -0.3, -0.1, regular_trapezoid);
   fl->inp_mem_fns[in_x_dot][in_ze] = init_trapz(-0.3, -0.1, 0.1, 0.3, regular_trapezoid);
   fl->inp_mem_fns[in_x_dot][in_ps] = init_trapz(0.1, -0.3, 1.7, 2.8, regular_trapezoid);
   fl->inp_mem_fns[in_x_dot][in_pl] = init_trapz(1.7, 2.8, 0, 0, right_trapezoid);

   /* The theta membership functions */
   //enter the appropriate membership function initialisations here

   fl->inp_mem_fns[in_theta][in_nl] = init_trapz(-0.1, -0.08, 0, 0, left_trapezoid);
   fl->inp_mem_fns[in_theta][in_ns] = init_trapz(-0.1, -0.08, -0.01, -0, regular_trapezoid);
   fl->inp_mem_fns[in_theta][in_ze] = init_trapz(-0.01, 0, 0, 0.01, regular_trapezoid);
   fl->inp_mem_fns[in_theta][in_ps] = init_trapz(0.0, 0.01, 0.08, 0.1, regular_trapezoid);
   fl->inp_mem_fns[in_theta][in_pl] = init_trapz(0.1, 0.08, 0, 0, right_trapezoid);
  	
   /* The theta dot membership functions */
   //enter the appropriate membership function initialisations here

   fl->inp_mem_fns[in_theta_dot][in_nl] = init_trapz(-0.30, -0.2, 0, 0, left_trapezoid);
   fl->inp_mem_fns[in_theta_dot][in_ns] = init_trapz(-0.30, -0.2, -0.01, 0, regular_trapezoid);
   fl->inp_mem_fns[in_theta_dot][in_ze] = init_trapz(-0.01, 0, 0, 0.01, regular_trapezoid);
   fl->inp_mem_fns[in_theta_dot][in_ps] = init_trapz(0, 0.01, 0.2, 0.3, regular_trapezoid);
   fl->inp_mem_fns[in_theta_dot][in_pl] = init_trapz(0.2, 0.3, 0, 0, right_trapezoid);

   return;
}

void initFuzzySystem (fuzzy_system_rec *fl) {

   //Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 50;
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;
	
	//Sample only
	fl->output_values[out_nvl]= -100.0;
	fl->output_values[out_nl] = -75.0;
   fl->output_values[out_nm] = -50.0;
   fl->output_values[out_ns] = -25.0;
   fl->output_values[out_ze] = 0.0;
   fl->output_values[out_ps] = 25.0;
   fl->output_values[out_pm] = 50.0;
   fl->output_values[out_pl] = 75.0;
   fl->output_values[out_pvl] = 100.0;

   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
   initFuzzyRules(fl);
   initMembershipFunctions(fl);
   return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {
	
   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp) {
	   
      case regular_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 1.0/(trz.c - trz.d);
         	 break;
	 
      case left_trapezoid:
         	 trz.r_slope = 1.0/(trz.a - trz.b);
         	 trz.l_slope = 0.0;
         	 break;
	 
      case right_trapezoid:
         	 trz.l_slope = 1.0/(trz.b - trz.a);
         	 trz.r_slope = 0.0;
         	 break;
   }  /* end switch  */
   
   return trz;
}  /* end function */

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
   switch (trz.tp) {
	   
      case left_trapezoid:
         	 if (x <= trz.a)
         	    return 1.0;
         	 if (x >= trz.b)
         	    return 0.0;
         	 /* a < x < b */
         	 return trz.r_slope * (x - trz.b);
	 
	 
      case right_trapezoid:
         	 if (x <= trz.a)
         	    return 0.0;
         	 if (x >= trz.b)
         	    return 1.0;
         	 /* a < x < b */
         	 return trz.l_slope * (x - trz.a);
	 
      case regular_trapezoid:
         	 if ((x <= trz.a) || (x >= trz.d))
         	    return 0.0;
         	 if ((x >= trz.b) && (x <= trz.c))
         	    return 1.0;
         	 if ((x >= trz.a) && (x <= trz.b))
         	    return trz.l_slope * (x - trz.a);
         	 if ((x >= trz.c) && (x <= trz.d))
         	    return  trz.r_slope * (x - trz.d);
         	    
	 }  /* End switch  */
	 
   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
   int i;
   float val;
   val = values [0];
   for (i = 1;i < no_of_inps;i++) {
       if (values[i] < val)
	  val = values [i];
   }
   return val;
}



//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
   int i,j;
   short variable_index,fuzzy_set;
   float sum1 = 0.0,sum2 = 0.0,weight;
   float m_values[MAX_NO_OF_INPUTS];
   
   for (i = 0;i < fz.no_of_rules;i++) {
      for (j = 0;j < fz.no_of_inputs;j++) {
	   variable_index = fz.rules[i].inp_index[j];
	   fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
	   m_values[j] = trapz(inputs[variable_index],
	       fz.inp_mem_fns[variable_index][fuzzy_set]);
	   } /* end j  */
      
       weight = min_of (m_values,fz.no_of_inputs);
				
       sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
       sum2 += weight;
   } /* end i  */
 
	if (fabs(sum2) < TOO_SMALL) {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //~ getch();
      //~ exit(1);
      return 0.0;
   }
   
   return (sum1/sum2);
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
   if (fz->allocated){
	   free (fz->rules);
	}
	
   fz->allocated = false;
   return;
}

