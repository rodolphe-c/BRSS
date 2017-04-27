// Copyright © 2017 Rodolphe Cargnello, rodolphe.cargnello@gmail.com

// This file is part of BRSS.

// BRSS is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// BRSS is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Affero General Public License for more details.
// You should have received a copy of the GNU Affero General Public License
// along with BRSS. If not, see <http://www.gnu.org/licenses/>



#include "brss/compiler.hpp"
#include <cmath>
#include <random>
#include <fstream>
#include <chrono>       // std::chrono::system_clock
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

using namespace std;

const int TIME = 1000;//60000000; //vrai temps : 6 * 10^7 micro s
const double ALPHA = 0.00000074;

double propension(brss::reaction react, std::vector<int> pop, int dim);
int calcul_n(double propension, float random);
int dimens = 0;


using point = std::pair<int,std::vector<int>>;

int main(int argc, char** argv)
{
	try
	{
		unsigned int cpt_reactions = 0;
		std::vector<brss::error_t> warnings;
		auto p = brss::parser(brss::lex(argv[1]), warnings);
		dimens = p.dimension;
		std::vector<brss::reaction> liste_reactions(p.reactions);
		std::vector<int> vector_of_pop;
		std::vector<point> vecteur_pop_en_cours;
		
		//variable aléatoire entre 0 et 1
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_real_distribution<> dis(0, 1);
		
		//ajout molecule dans vector
		
		for(size_t i=0; i< p.molecules_index.size(); ++i){
			vector_of_pop.push_back(p.molecules_index[i].get().popinit);
		}
		
		//affichage
		/*for(size_t i=0; i< vector_of_pop.size(); ++i){
			cout<<"contenu de vector_of_pop "<< vector_of_pop[i]<<endl;
		}*/
		
		/*
		//affichage liste_reactions
		for (int i = 0; i < p.reactions.size(); ++i)
		{
			std::cout << liste_reactions[i] << endl;
		}
		*/
		
		//Simulation de reaction aleatoire
		for(size_t i = 0; i < TIME; i+=100)
		{
			// cout<<"size de liste reac : "<<liste_reactions.size()<<" size de cpt : "<<cpt_reactions<<endl;
			
			//choisir une réaction aléatoirement
			if(cpt_reactions > liste_reactions.size()-1)
			{
				// obtain a time-based seed:
		   	    long long int seed = std::chrono::system_clock::now().time_since_epoch().count();
			    shuffle (liste_reactions.begin(), liste_reactions.end(), std::default_random_engine(seed));
				//std::random_shuffle ( liste_reactions.begin(), liste_reactions.end() );
				cpt_reactions = 0;
			}
			
			for(size_t b = 0; b<liste_reactions.size(); ++b){
				cout<<"reaction de la liste : "<<liste_reactions[b]<<endl;
			}
			
			//vecteur contenant une paire (index de la molecule/popinit)
			std::vector<std::pair<size_t, int>> vect;
			for(size_t k = 0; k < liste_reactions[cpt_reactions].left_molecules.size(); k++)
			{	
				//population initiales des reactifs (gauche)
				unsigned int poo = p.molecules_index[liste_reactions[cpt_reactions].left_molecules[k]].get().popinit;
				//cout << "Nombre popinit " << poo << endl;
				
				std::pair<size_t, int> pp(liste_reactions[cpt_reactions].left_molecules[k], poo);
				vect.push_back(pp);
			}
			
			/*for(int k = 0; k < vect.size(); k++)
			{	
				cout<<"........................"<<endl;
				cout<<"VECTEUR   part1 : "<<vect[k].first<<" VECTEUR   part2 : "<<vect[k].second<<endl;
				cout<<"........................"<<endl;
				
			}*/
		
			double rand = (double)dis(gen);
			double prop = propension(liste_reactions[cpt_reactions], vector_of_pop, dimens);
			int n = 0; 
			n = calcul_n(prop, (float)rand);
			
			//cout <<"propension : " << prop<<endl;
			//cout << "variable aleatoire : " << rand << endl;
			cout << "n : " << n << endl;
			cout << "------------------" << endl;
			
			
			
			//booleen permettant de verifier si la reaction a ete faite
			//sert lorsque m1 et/ou m2 vont valoir 0 a la derniere iteration
			//on doit quand meme ajouter une molecule a m3 avant de stabiliser la reaciton...
			bool fait;
			//nous permet de realiser la reaction meme si n > a la population des reactifs (gauche)
			int nPetit;
			
			//Ajout et Suppression de molecule apres calcul de n
			//pour chaque reaction 
			
			//pour chaque molécule de la réaction
			//cas suppression molecule
			for(size_t c = 0; c < liste_reactions[cpt_reactions].left_molecules.size(); c++)
			{
				fait = false;
				nPetit = 0;
				//cout<<"test :"<<liste_reactions[cpt_reactions].left_molecules.size()<<endl;
				//dans le cas de 2 molecules a gauche
				if(c == 0 && liste_reactions[cpt_reactions].left_molecules.size() == 2)
				{
					//si les 2 molecules sont > 0
					if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] > 0 && vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] > 0)
					{
						//suppression molecules "reactifs" (gauche)
						if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] >= n && vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] >= n){
							vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] -= n;
							vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] -= n;
						}
						else if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] < n){
							nPetit = vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]];
							vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] = 0;
							vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] -= n;
						}
						else{
							nPetit = vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]];
							vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] = 0;
							vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] -= n;
						}
						
						cout <<"---------------SUPPRESSION------------"<< endl;
						for(unsigned int r=0; r<vector_of_pop.size(); ++r)
						{
							cout << "m"<<r+1<<": " << vector_of_pop[r] << endl;
						}
						cout <<"--------------------------------------"<< endl;
						// cout << "val : " << vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] << endl;
						// cout << "indice : " << liste_reactions[cpt_reactions].left_molecules[c] << endl;
						// cout << "taille indice : " << liste_reactions[cpt_reactions].left_molecules.size() << endl;
						fait = true;
					}
					//sinon je laisse à 0
					else if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] == 0 && vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] == 0)
					{
						//reaction impossible
						vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] =0;
						vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] =0;
						cout <<"---------------PAS SUPPRESSION------------"<< endl;
						for(unsigned int r=0; r<vector_of_pop.size(); ++r)
						{
							cout << "m"<<r+1<<": " << vector_of_pop[r] << endl;
						}
						cout <<"------------------------------------------"<< endl;
						// cout << "val : " << vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] << endl;
						// cout << "indice : " << liste_reactions[cpt_reactions].left_molecules[c] << endl;
						// cout << "taille indice : " << liste_reactions[cpt_reactions].left_molecules.size() << endl;
						fait = false;
					}
				}
				//idem pour le cas avec 1 molecule a gauche
				else if(c == 0 && liste_reactions[cpt_reactions].left_molecules.size() == 1)
				{
					if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] > 0)
					{
						//suppression molecules "reactifs" (gauche)
						if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] >= n ){
							vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] -= n;
						}
						else if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] < n){
							nPetit = vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]];
							vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] = 0;
						}
						
						cout <<"---------------SUPPRESSION------------"<< endl;
						for(unsigned int r=0; r<vector_of_pop.size(); ++r)
						{
							cout << "m"<<r+1<<": " << vector_of_pop[r] << endl;
						}
						cout <<"--------------------------------------"<< endl;
						// cout << "val : " << vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] << endl;
						// cout << "indice : " << liste_reactions[cpt_reactions].left_molecules[c] << endl;
						// cout << "taille indice : " << liste_reactions[cpt_reactions].left_molecules.size() << endl;
						fait = true;
					}
					else if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] == 0)
					{
						//reaction impossible
						vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] = 0;
						cout <<"---------------PAS SUPPRESSION------------"<< endl;
						for(unsigned int r=0; r<vector_of_pop.size(); ++r)
						{
							cout << "m"<<r+1<<": " << vector_of_pop[r] << endl;
						}
						cout <<"------------------------------------------"<< endl;
						// cout << "val : " << vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] << endl;
						// cout << "indice : " << liste_reactions[cpt_reactions].left_molecules[c] << endl;
						// cout << "taille indice : " << liste_reactions[cpt_reactions].left_molecules.size() << endl;
						fait = false;
					}
				}
			}
			
			
			//meme proceder pour les molecules de droites
			for(size_t c = 0; c < liste_reactions[cpt_reactions].right_molecules.size(); c++)
			{
				//cout<<"test :"<<liste_reactions[cpt_reactions].left_molecules.size()<<endl;
				if(c == 0 && liste_reactions[cpt_reactions].right_molecules.size() == 2)
				{
					if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] > 0 || fait == true)
					{
						//ajout molecules "produits" (droite)
						if(nPetit == 0){
							vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c]] += n;
							vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c+1]] += n;
						}
						else{
							vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c]] += nPetit;
							vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c+1]] += nPetit;
						}
						
						cout <<"---------------AJOUT------------"<< endl;
						for(unsigned int r=0; r<vector_of_pop.size(); ++r)
						{
							cout << "m"<<r+1<<": " << vector_of_pop[r] << endl;
						}
						cout <<"--------------------------------"<< endl;
						// cout << "val : " << vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] << endl;
						// cout << "indice : " << liste_reactions[cpt_reactions].left_molecules[c] << endl;
						
					}
					else if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] == 0)
					{
						//ajout impossible
						vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c]] = vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c]];
						vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c+1]] = vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c+1]];
						cout <<"---------------PAS AJOUT------------"<< endl;
						for(unsigned int r=0; r<vector_of_pop.size(); ++r)
						{
							cout << "m"<<r+1<<": " << vector_of_pop[r] << endl;
						}
						cout <<"--------------------------------"<< endl;
						// cout << "val : " << vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] << endl;
						// cout << "indice : " << liste_reactions[cpt_reactions].left_molecules[c] << endl;
						
					}
				}
			
				else if(c == 0 && liste_reactions[cpt_reactions].right_molecules.size() == 1)
				{
					if((vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] > 0 && vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] > 0) || fait == true)
					{
						//ajout molecules "produits" (droite)
						if(nPetit == 0){
							vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c]] += n;
						}
						else{
							vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c]] += nPetit;
						}
						cout <<"---------------AJOUT------------"<< endl;
						for(unsigned int r=0; r<vector_of_pop.size(); ++r)
						{
							cout << "m"<<r+1<<": " << vector_of_pop[r] << endl;
						}
						cout <<"--------------------------------"<< endl;
						//cout << "val : " << vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] << endl;
						//cout << "indice : " << liste_reactions[cpt_reactions].left_molecules[c] << endl;
					}
					else if(vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] == 0 && vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c+1]] == 0)
					{
						//ajout impossible
						vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c]] = vector_of_pop[liste_reactions[cpt_reactions].right_molecules[c]];
						cout <<"---------------PAS AJOUT------------"<< endl;
						for(unsigned int r=0; r<vector_of_pop.size(); ++r)
						{
							cout << "m"<<r+1<<": " << vector_of_pop[r] << endl;
						}
						cout <<"--------------------------------"<< endl;
						//cout << "val : " << vector_of_pop[liste_reactions[cpt_reactions].left_molecules[c]] << endl;
						//cout << "indice : " << liste_reactions[cpt_reactions].left_molecules[c] << endl;
					}
				}
			}
			
			//contiendra la population en cours (augmentation ou suppression)
			vecteur_pop_en_cours.push_back(point(i, vector_of_pop));
			cpt_reactions++;
		}
		
		/*for(int y = 0; y<vecteur_pop_en_cours.size(); ++y){
			for(int z = 0; z<vecteur_pop_en_cours[y].second.size(); ++z){
				//contient le nombre de population actuelle
				cout<<"contenu de vecteur_pop_en_cours : "<<vecteur_pop_en_cours[y].second[z]<<endl;
			}
			cout<<""<<endl;
		}*/
		
		//creation d un fichier afin de generer un graphique
		//de notre réaction
		ofstream myfile;
		myfile.open ("pop.dat");
		
		for(size_t l=0; l < p.molecules_index.size(); ++l)
		{
			//devrait demarquer une courbe d une autre
			myfile << "#\"" << p.molecules_index[l].get().id << "\"\n";
			myfile << "#X" << "\t" << "Y\n";
			for (unsigned int o = 0; o < vecteur_pop_en_cours.size(); o++)
			{
				//structure de donnees du type : temps actuel ==> population actuelle
				myfile << vecteur_pop_en_cours[o].first << "\t" << vecteur_pop_en_cours[o].second[l] << "\n";
			}
			myfile << "\n";
		}
		myfile.close();
		
		//resultat final apres avoir terminer toutes les reactions
		for(unsigned int r=0; r<vector_of_pop.size(); ++r)
		{
			cout << "m"<<r+1<<" finale : " << vector_of_pop[r] << endl;
		}
		
	}
	
	catch (brss::error_t const & e)
	{
		std::cerr << "\033[31mERROR " << e.first << "\033[0m " << e.second << std::endl;
		exit(2);
	}

	return 0;
}


//calcul de la propension
//propension : nombre moyen de choc * cinétique de la reaction
double propension(brss::reaction react, std::vector<int> pop, int dim)
{
	double rep = 0.0;
	
	if(react.left_molecules.size() == 1){
		cout<<"pop molecule 0 :"<<pop[react.left_molecules[0]]<<endl;
		rep = (double)((pop[react.left_molecules[0]]) * (double)react.proba); 
	}
	else{
		//std::cout<<"test dimension : "<<dim<<std::endl;
		//mettre le diametre en micrometre
		double d = double(dim)/1000;
		double volume = (4*M_PI*(std::pow((d/2), 3)))/3;
		//resultat en micrometre cube
		cout<<"pop molecule 0 :"<<pop[react.left_molecules[0]]<<endl;
		cout<<"pop molecule 1 :"<<pop[react.left_molecules[1]]<<endl;
		rep = (double)(ALPHA*((pop[react.left_molecules[0]]*pop[react.left_molecules[1]])/volume)*react.proba);
	}
	return rep;
}

//calcul de n
//regulera l ajout et la suppression de molecule
int calcul_n(double propension, float random)
{
	
	double param, fractpart, intpart;

    param = propension;
    //permet d avoir la partie entiere de la propension
	fractpart = modf (param , &intpart);
	
	//std::cout << "propension : "<<propension<<" , et la partie dec : "<< fractpart << std::endl;
	
	//std::cout << "partie dec : " << fractpart << std::endl;
	// std::cout << "random : " << random << std::endl;
	if(fractpart <= random){
		return int(propension);
	}
	else{
		return int(propension)+1;
	}
}
