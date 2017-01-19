// Copyright © 2015 Rodolphe Cargnello, rodolphe.cargnello@gmail.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "../../color.hpp"

/**
 * @brief LaTex colors
 *
 * @code
 #include <hnc/color.hpp>
 @endcode
 *
 * http://latexcolor.com/
 */

class latex
{
	/// @brief Air Force blue color
	/// @return Air Force blue color
	static hopp::color blue_air_force() { return { 91u, 137u, 170u }; }
	
	/// @brief Alice blue color
	/// @return Alice blue color
	static hopp::color blue_alice() { return { 240u, 248u, 255u }; }
	
	/// @brief Alizarin color
	/// @return Alizarin color
	static hopp::color alizarin() { return { 229u, 43u, 49u }; }
	
	/// @brief Almond color
	/// @return Almond color
	static hopp::color almond() { return { 239u, 222u, 204u }; }

	/// @brief Amaranth color
	/// @return Amaranth color
	static hopp::color amaranth() { return { 231u, 47u, 78u }; }
	
	/// @brief Amber color
	/// @return Amber color
	static hopp::color amber() { return { 255u, 193u, 0u }; }
	
	/// @brief Amber (SAE/ECE) color
	/// @return Amber (SAE/ECE) color
	static hopp::color amber2() { return { 255u, 128u, 0u }; }
	
	/// @brief American rose color
	/// @return American rose color
	static hopp::color rose_american() { return { 255u, 20u, 57u }; }
	
	/// @brief Amethyst color
	/// @return Amethyst color
	static hopp::color amethyst() { return { 153u, 100u, 208u }; }
	
	/// @brief Anti-flash white color
	/// @return Anti-flash white color
	static hopp::color white_anti_flash() { return { 242u, 243u, 244u }; }
	
	/// @brief Antique brass color
	/// @return Antique brass color
	static hopp::color brass_antique() { return { 206u, 150u, 114u }; }
	
	/// @brief Antique fuchsia color
	/// @return Antique fuchsia color
	static hopp::color fuchsia_antique() { return { 146u, 92u, 132u }; }
	
	/// @brief Antique white color
	/// @return Antique white color
	static hopp::color white_antique() { return { 250u, 235u, 214u }; }
	
	/// @brief Ao color
	/// @return Ao color
	static hopp::color ao() { return { 0u, 0u, 255u }; }
	
	/// @brief Ao (English) color
	/// @return Ao (English) color
	static hopp::color ao_english() { return { 0u, 128u, 0u }; }
	
	/// @brief Apple green color
	/// @return Apple green color
	static hopp::color green_apple() { return { 141u, 183u, 0u }; }
	
	/// @brief Apricot color
	/// @return Apricot color
	static hopp::color apricot() { return { 252u, 207u, 175u }; }
	
	/// @brief Aqua color
	/// @return Aqua color
	static hopp::color aqua() { return { 0u, 254u, 255u }; }
	
	/// @brief Aquamarine color
	/// @return Aquamarine color
	static hopp::color aquamarine() { return { 123u, 255u, 206u }; }
	
	/// @brief Army green color
	/// @return Army green color
	static hopp::color green_army() { return { 75u, 83u, 26u }; }
	
	/// @brief Arsenic color
	/// @return Arsenic color
	static hopp::color arsenic() { return { 59u, 68u, 75u }; }
	
	/// @brief Arylide yellow color
	/// @return Arylide yellow color
	static hopp::color yellow_arylide() { return { 234u, 215u, 95u }; }
	
	/// @brief Ash grey color
	/// @return Ash grey color
	static hopp::color grey_ash() { return { 178u, 190u, 181u }; }
	
	/// @brief Asparagus color
	/// @return Asparagus color
	static hopp::color asparagus() { return { 135u, 170u, 102u }; }
	
	/// @brief Atomic tangerine color
	/// @return Atomic tangerine color
	static hopp::color tangerine_atomic() { return { 255u, 155u, 95u }; }
	
	/// @brief Auburn color
	/// @return Auburn color
	static hopp::color auburn() { return { 110u, 54u, 21u }; }
	
	/// @brief Aureolin color
	/// @return Aureolin color
	static hopp::color aureolin() { return { 254u, 240u, 0u }; }
	
	/// @brief AuroMetalSaurus color
	/// @return AuroMetalSaurus color
	static hopp::color auro_metal_saurus() { return { 110u, 127u, 128u }; }
	
	/// @brief Awesome color
	/// @return Awesome color
	static hopp::color awesome() { return { 255u, 39u, 79u }; }
	
	/// @brief Azure wheel color
	/// @return Azure wheel color
	static hopp::color azure_wheel() { return { 0u, 123u, 255u }; }
	
	/// @brief Azure mist color
	/// @return Azure mist color
	static hopp::color azure_mist() { return { 240u, 255u, 255u }; }
	
	/// @brief Baby blue color
	/// @return Baby blue color
	static hopp::color blue_baby() { return { 135u, 206u, 242u }; }
	
	/// @brief Baby blue eyes color
	/// @return Baby blue eyes color
	static hopp::color blue_baby_eyes() { return { 160u, 201u, 243u }; }
	
	/// @brief Baby pink color
	/// @return Baby pink color
	static hopp::color pink_baby() { return { 245u, 194u, 193u }; }
	
	/// @brief Ball blue color
	/// @return Ball blue color
	static hopp::color blue_ball() { return { 17u, 170u, 207u }; }
	
	/// @brief Banana Mania color
	/// @return Banana Mania color
	static hopp::color banana_mania() { return { 251u, 232u, 177u }; }
	
	/// @brief Banana yellow color
	/// @return Banana yellow color
	static hopp::color yellow_banana() { return { 255u, 227u, 0u }; }
	
	/// @brief Battleship grey color
	/// @return Battleship grey color
	static hopp::color grey_battleship() { return { 132u, 132u, 130u }; }
	
	/// @brief Bazaar color
	/// @return Bazaar color
	static hopp::color bazaar() { return { 153u, 119u, 123u }; }
	
	/// @brief Beau blue color
	/// @return Beau blue color
	static hopp::color blue_beau() { return { 187u, 212u, 231u }; }
	
	/// @brief Beaver color
	/// @return Beaver color
	static hopp::color beaver() { return { 160u, 129u, 111u }; }
	
	/// @brief Beige color
	/// @return Beige color
	static hopp::color beige() { return { 245u, 245u, 218u }; }
	
	/// @brief Bisque color
	/// @return Bisque color
	static hopp::color bisque() { return { 255u, 229u, 194u }; }
	
	/// @brief Bistre color
	/// @return Bistre color
	static hopp::color bistre() { return { 61u, 43u, 30u }; }
	
	/// @brief Bittersweet color
	/// @return Bittersweet color
	static hopp::color bittersweet() { return { 255u, 113u, 90u }; }
	
	/// @brief Black color
	/// @return Black color
	static hopp::color black() { return { 0u, 0u, 0u }; }
	
	/// @brief Blanched Almond color
	/// @return Blanched Almond color
	static hopp::color blanched_almond() { return { 255u, 236u, 203u }; }
	
	/// @brief Bleu de France color
	/// @return Bleu de France color
	static hopp::color bleu_de_france() { return { 40u, 138u, 235u }; }
	
	/// @brief Blizzard Blue color
	/// @return Blizzard Blue color
	static hopp::color blue_blizzard() { return { 170u, 229u, 239u }; }
	
	/// @brief Blond color
	/// @return Blond color
	static hopp::color blond() { return { 251u, 241u, 186u }; }
	
	/// @brief Blue color
	/// @return Blue color
	static hopp::color blue() { return { 0u, 0u, 255u }; }
	
	/// @brief Blue (Munsell) color
	/// @return Blue (Munsell) color
	static hopp::color blue_munsell() { return { 0u, 146u, 177u }; }
	
	/// @brief Blue (NCS) color
	/// @return Blue (NCS) color
	static hopp::color blue_ncs() { return { 0u, 134u, 192u }; }
	
	/// @brief Blue (pigment) color
	/// @return Blue (pigment) color
	static hopp::color blue_pigment() { return { 49u, 47u, 157u }; }
	
	/// @brief Blue (RYB) color
	/// @return Blue(RYB) color
	static hopp::color blue_ryb() { return { 0u, 62u, 255u }; }
	
	/// @brief Blue Bell color
	/// @return Blue Bell color
	static hopp::color blue_bell() { return { 162u, 161u, 210u }; }
	
	/// @brief Blue Gray color
	/// @return Blue Gray color
	static hopp::color blue_gray() { return { 100u, 152u, 207u }; }
	
	/// @brief Blue-green color
	/// @return Blue-green color
	static hopp::color blue_green() { return { 0u, 220u, 222u }; }
	
	/// @brief Blue-violet color
	/// @return Blue-violet color
	static hopp::color blue_violet() { return { 138u, 32u, 231u }; }
	
	/// @brief Blush color
	/// @return Blush color
	static hopp::color blush() { return { 224u, 94u, 131u }; }
	
	/// @brief Bole color
	/// @return Bole color
	static hopp::color bole() { return { 122u, 69u, 58u }; }
	
	/// @brief Bondi blue color
	/// @return Bondi blue color
	static hopp::color blue_bondi() { return { 0u, 148u, 184u }; }
	
	/// @brief Boston University Red color
	/// @return Boston University Red color
	static hopp::color red_boston_university() { return { 206u, 13u, 0u }; }
	
	/// @brief Brandeis blue color
	/// @return Brandeis blue color
	static hopp::color blue_brandeis() { return { 0u, 107u, 255u }; }
	
	/// @brief Brass color
	/// @return Brass color
	static hopp::color brass() { return { 182u, 167u, 52u }; }
	
	/// @brief Brick red color
	/// @return Brick red color
	static hopp::color red_brick() { return { 205u, 67u, 83u }; }
	
	/// @brief Bright cerulean color
	/// @return Bright cerulean color
	static hopp::color cerulean_bright() { return { 7u, 171u, 217u }; }
	
	/// @brief Bright green color
	/// @return Bright green color
	static hopp::color green_bright() { return { 98u, 255u, 0u }; }
	
	/// @brief Bright lavender color
	/// @return Bright lavender color
	static hopp::color lavender_bright() { return { 191u, 147u, 231u }; }
	
	/// @brief Bright maroon color
	/// @return Bright maroon color
	static hopp::color maroon_bright() { return { 197u, 36u, 71u }; }
	
	/// @brief Bright pink color
	/// @return Bright pink color
	static hopp::color pink_bright() { return { 255u, 11u, 128u }; }
	
	/// @brief Bright turquoise color
	/// @return Bright turquoise color
	static hopp::color turquoise_bright() { return { 0u, 231u, 222u }; }
	
	/// @brief Bright ube color
	/// @return Bright ube color
	static hopp::color ube_bright() { return { 209u, 158u, 235u }; }
	
	/// @brief Brilliant lavender color
	/// @return Brilliant lavender color
	static hopp::color lavender_brilliant() { return { 245u, 186u, 255u }; }
	
	/// @brief Brilliant rose color
	/// @return Brilliant rose color
	static hopp::color rose_brilliant() { return { 255u, 86u, 164u }; }
	
	/// @brief Brink pink color
	/// @return Brink pink color
	static hopp::color pink_brink() { return { 253u, 98u, 126u }; }
	
	/// @brief British racing green color
	/// @return British racing green color
	static hopp::color green_british_racing() { return { 0u, 66u, 35u }; }
	
	/// @brief Bronze color
	/// @return Bronze color
	static hopp::color bronze() { return { 206u, 128u, 36u }; }
	
	/// @brief Brown (traditional) color
	/// @return Brown (traditional) color
	static hopp::color brown_traditional() { return { 151u, 76u, 0u }; }
	
	/// @brief Brown (web) color
	/// @return Brown (web) color
	static hopp::color brown_web() { return { 166u, 44u, 38u }; }
	
	/// @brief Bubble gum color
	/// @return Bubble gum color
	static hopp::color bubble_gum() { return { 255u, 193u, 204u }; }
	
	/// @brief Bubbles color
	/// @return Bubbles color
	static hopp::color bubbles() { return { 230u, 254u, 255u }; }
	
	/// @brief Buff color
	/// @return Buff color
	static hopp::color buff() { return { 241u, 221u, 122u }; }
	
	/// @brief Bulgarian rose color
	/// @return Bulgarian rose color
	static hopp::color rose_bulgarian() { return { 73u, 7u, 5u }; }
	
	/// @brief Burgundy color
	/// @return Burgundy color
	static hopp::color burgundy() { return { 129u, 4u, 30u }; }
	
	/// @brief Burlywood color
	/// @return Burlywood color
	static hopp::color burlywood() { return { 223u, 185u, 131u }; }
	
	/// @brief Burnt orange color
	/// @return Burnt orange color
	static hopp::color orange_burnt() { return { 206u, 87u, 0u }; }
	
	/// @brief Burnt sienna color
	/// @return Burnt sienna color
	static hopp::color sienna_burnt() { return { 235u, 118u, 75u }; }
	
	/// @brief Burnt umber color
	/// @return Burnt umber color
	static hopp::color umber_burnt() { return { 139u, 52u, 32u }; }
	
	/// @brief Byzantine color
	/// @return Byzantine color
	static hopp::color byzantine() { return { 190u, 49u, 167u }; }
	
	/// @brief Byzantium color
	/// @return Byzantium color
	static hopp::color byzantium() { return { 113u, 40u, 101u }; }
	
	/// @brief Cadet color
	/// @return Cadet color
	static hopp::color cadet() { return { 82u, 104u, 115u }; }
	
	/// @brief Cadet blue color
	/// @return Cadet blue color
	static hopp::color blue_cadet() { return { 93u, 158u, 161u }; }
	
	/// @brief Cadet grey color
	/// @return Cadet grey color
	static hopp::color grey_cadet() { return { 144u, 163u, 177u }; }
	
	/// @brief Cadmium Green color
	/// @return Cadmium Green color
	static hopp::color green_cadmium() { return { 0u, 107u, 57u }; }
	
	/// @brief Cadmium Orange color
	/// @return Cadmium Orange color
	static hopp::color orange_cadmium() { return { 239u, 137u, 22u }; }
	
	/// @brief Cadmium Red color
	/// @return Cadmium Red color
	static hopp::color red_cadmium() { return { 229u, 15u, 25u }; }
	
	/// @brief Cadmium Yellow color
	/// @return Cadmium Yellow color
	static hopp::color yellow_cadmium() { return { 255u, 248u, 0u }; }
	
	/// @brief Cal Poly Pomona green color
	/// @return Cal Poly Pomona green color
	static hopp::color green_cal_poly_pomona() { return { 29u, 77u, 41u }; }
	
	/// @brief Cambridge Blue color
	/// @return Cambridge Blue color
	static hopp::color blue_cambridge() { return { 163u, 193u, 172u }; }
	
	/// @brief Camel color
	/// @return Camel color
	static hopp::color camel() { return { 194u, 155u, 103u }; }
	
	/// @brief Camouflage green color
	/// @return Camouflage green color
	static hopp::color green_camouflage() { return { 120u, 134u, 105u }; }
	
	/// @brief Canary yellow color
	/// @return Canary yellow color
	static hopp::color yellow_canary() { return { 255u, 241u, 0u }; }
	
	/// @brief Candy apple red color
	/// @return Candy apple red color
	static hopp::color red_candy_apple() { return { 255u, 24u, 0u }; }
	
	/// @brief Candy pink color
	/// @return Candy pink color
	static hopp::color pink_candy() { return { 230u, 114u, 121u }; }
	
	/// @brief Capri color
	/// @return Capri color
	static hopp::color capri() { return { 0u, 189u, 255u }; }
	
	/// @brief Caput mortuum color
	/// @return Caput mortuum color
	static hopp::color caput_mortuum() { return { 90u, 40u, 30u }; }
	
	/// @brief Cardinal color
	/// @return Cardinal color
	static hopp::color cardinal() { return { 198u, 34u, 56u }; }
	
	/// @brief Caribbean green color
	/// @return Caribbean green color
	static hopp::color green_caribbean() { return { 0u, 204u, 151u }; }
	
	/// @brief Carmine color
	/// @return Carmine color
	static hopp::color carmine() { return { 151u, 6u, 19u }; }
	
	/// @brief Carmine pink color
	/// @return Carmine pink color
	static hopp::color pink_carmine() { return { 237u, 79u, 61u }; }
	
	/// @brief Carmine red color
	/// @return Carmine red color
	static hopp::color red_carmine() { return { 255u, 18u, 50u }; }
	
	/// @brief Carnation pink color
	/// @return Carnation pink color
	static hopp::color pink_carnation() { return { 255u, 166u, 202u }; }
	
	/// @brief Carnelian color
	/// @return Carnelian color
	static hopp::color carnelian() { return { 181u, 31u, 19u }; }
	
	/// @brief Carolina blue color
	/// @return Carolina blue color
	static hopp::color blue_carolina() { return { 152u, 185u, 223u }; }
	
	/// @brief Carrot orange color
	/// @return Carrot orange color
	static hopp::color orange_carrot() { return { 239u, 147u, 0u }; }
	
	/// @brief Ceil color
	/// @return Ceil color
	static hopp::color ceil() { return { 145u, 160u, 209u }; }
	
	/// @brief Celadon color
	/// @return Celadon color
	static hopp::color celadon() { return { 171u, 225u, 172u }; }
	
	/// @brief Celestrial blue color
	/// @return Celestrial blue color
	static hopp::color blue_celestrial() { return { 69u, 150u, 211u }; }
	
	/// @brief Cerise color
	/// @return Cerise color
	static hopp::color cerise() { return { 224u, 52u, 99u }; }
	
	/// @brief Cerise pink color
	/// @return Cerise pink color
	static hopp::color pink_cerise() { return { 238u, 61u, 132u }; }
	
	/// @brief Cerulean color
	/// @return Cerulean color
	static hopp::color cerulean() { return { 0u, 122u, 169u }; }
	
	/// @brief Cerulean blue color
	/// @return Cerulean blue color
	static hopp::color blue_cerulean() { return { 37u, 79u, 194u }; }
	
	/// @brief Chamoisee color
	/// @return Chamoisee color
	static hopp::color chamoisee() { return { 161u, 121u, 87u }; }
	
	/// @brief Champagne color
	/// @return Champagne color
	static hopp::color champagne() { return { 247u, 231u, 204u }; }
	
	/// @brief Charcoal color
	/// @return Charcoal color
	static hopp::color charcoal() { return { 54u, 69u, 80u }; }
	
	/// @brief Chartreuse (traditional) color
	/// @return Chartreuse (traditional) color
	static hopp::color chartreuse_traditional() { return { 223u, 255u, 0u }; }
	
	/// @brief Chartreuse (web) color
	/// @return Chartreuse (web) color
	static hopp::color chartreuse_web() { return { 125u, 255u, 0u }; }
	
	/// @brief Cherry blossom pink color
	/// @return Cherry blossom pink color
	static hopp::color pink_cherry_blossom() { return { 255u, 183u, 197u }; }
	
	/// @brief Chestnut color
	/// @return Chestnut color
	static hopp::color chestnut() { return { 207u, 93u, 90u }; }
	
	/// @brief Chocolate (traditional) color
	/// @return Chocolate (traditional) color
	static hopp::color chocolate_traditional() { return { 124u, 64u, 0u }; }
	
	/// @brief Chocolate (web) color
	/// @return Chocolate (web) color
	static hopp::color chocolate_web() { return { 212u, 107u, 3u }; }
	
	/// @brief Chrome yellow color
	/// @return Chrome yellow color
	static hopp::color yellow_chrome() { return { 255u, 169u, 0u }; }
	
	/// @brief Cinereous color
	/// @return Cinereous color
	static hopp::color cinereous() { return { 152u, 129u, 122u }; }
	
	/// @brief Cinnabar color
	/// @return Cinnabar color
	static hopp::color cinnabar() { return { 229u, 69u, 45u }; }
	
	/// @brief Cinnamon color
	/// @return Cinnamon color
	static hopp::color cinnamon() { return { 212u, 107u, 3u }; }
	
	/// @brief Citrine color
	/// @return Citrine color
	static hopp::color citrine() { return { 229u, 210u, 0u }; }
	
	/// @brief Classic rose color
	/// @return Classic rose color
	static hopp::color rose_classic() { return { 252u, 204u, 232u }; }
	
	/// @brief Cobalt color
	/// @return Cobalt color
	static hopp::color cobalt() { return { 0u, 68u, 175u }; }
	
	/// @brief Cocoa brown color
	/// @return Cocoa brown color
	static hopp::color brown_cocoa() { return { 212u, 107u, 3u }; }
	
	/// @brief Columbia blue color
	/// @return Columbia blue color
	static hopp::color blue_columbia() { return { 153u, 220u, 255u }; }
	
	/// @brief Cool black color
	/// @return Cool black color
	static hopp::color black_cool() { return { 0u, 44u, 101u }; }
	
	/// @brief Cool grey color
	/// @return Cool grey color
	static hopp::color grey_cool() { return { 140u, 146u, 173u }; }
	
	/// @brief Copper color
	/// @return Copper color
	static hopp::color copper() { return { 185u, 116u, 41u }; }
	
	/// @brief Copper rose color
	/// @return Copper rose color
	static hopp::color rose_copper() { return { 154u, 102u, 101u }; }
	
	/// @brief Coquelicot color
	/// @return Coquelicot color
	static hopp::color coquelicot() { return { 255u, 61u, 0u }; }
	
	/// @brief Coral color
	/// @return Coral color
	static hopp::color coral() { return { 255u, 129u, 72u }; }
	
	/// @brief Coral pink color
	/// @return Coral pink color
	static hopp::color pink_coral() { return { 250u, 132u, 118u }; }
	
	/// @brief Coral red color
	/// @return Coral red color
	static hopp::color red_coral() { return { 255u, 68u, 58u }; }
	
	/// @brief Cordovan color
	/// @return Cordovan color
	static hopp::color cordovan() { return { 138u, 64u, 68u }; }
	
	/// @brief Corn color
	/// @return Corn color
	static hopp::color corn() { return { 252u, 237u, 73u }; }
	
	/// @brief Cornell Red color
	/// @return Cornell Red color
	static hopp::color red_cornell() { return { 181u, 31u, 19u }; }
	
	/// @brief Cornflower blue color
	/// @return Cornflower blue color
	static hopp::color blue_cornflower() { return { 97u, 147u, 241u }; }
	
	/// @brief Cornsilk color
	/// @return Cornsilk color
	static hopp::color cornsilk() { return { 255u, 248u, 218u }; }
	
	/// @brief Cosmic latte color
	/// @return Cosmic latte color
	static hopp::color latte_cosmic() { return { 255u, 248u, 230u }; }
	
	/// @brief Cotton candy color
	/// @return Cotton candy color
	static hopp::color candy_cotton() { return { 255u, 188u, 218u }; }
	
	/// @brief Cream color
	/// @return Cream color
	static hopp::color cream() { return { 255u, 254u, 205u }; }
	
	/// @brief Crimson color
	/// @return Crimson color
	static hopp::color crimson() { return { 222u, 27u, 57u }; }
	
	/// @brief Crimson glory color
	/// @return Crimson glory color
	static hopp::color crimson_glory() { return { 192u, 10u, 47u }; }
	
	/// @brief Cyan color
	/// @return Cyan color
	static hopp::color cyan() { return { 0u, 254u, 255u }; }
	
	/// @brief Cyan (process) color
	/// @return Cyan (process) color
	static hopp::color cyan_process() { return { 0u, 182u, 238u }; }
	
	/// @brief Daffodil color
	/// @return Daffodil color
	static hopp::color daffodil() { return { 255u, 255u, 0u }; }
	
	/// @brief Dandelion color
	/// @return Dandelion color
	static hopp::color dandelion() { return { 241u, 227u, 0u }; }
	
	/// @brief Dark blue color
	/// @return Dark blue color
	static hopp::color blue_dark() { return { 0u, 0u, 143u }; }
	
	/// @brief Dark brown color
	/// @return Dark brown color
	static hopp::color brown_dark() { return { 102u, 68u, 29u }; }
	
	/// @brief Dark byzantium color
	/// @return Dark byzantium color
	static hopp::color byzantium_dark() { return { 93u, 57u, 85u }; }
	
	/// @brief Dark candy apple red color
	/// @return Dark candy apple red color
	static hopp::color red_candy_apple_dark() { return { 166u, 8u, 0u }; }
	
	/// @brief Dark cerulean color
	/// @return Dark cerulean color
	static hopp::color cerulean_dark() { return { 0u, 67u, 129u }; }
	
	/// @brief Dark champagne color
	/// @return Dark champagne color
	static hopp::color champagne_dark() { return { 195u, 179u, 124u }; }
	
	/// @brief Dark chestnut color
	/// @return Dark chestnut color
	static hopp::color chestnut_dark() { return { 153u, 106u, 95u }; }
	
	/// @brief Dark coral color
	/// @return Dark coral color
	static hopp::color coral_dark() { return { 207u, 93u, 65u }; }
	
	/// @brief Dark cyan color
	/// @return Dark cyan color
	static hopp::color cyan_dark() { return { 0u, 139u, 140u }; }
	
	/// @brief Dark electric blue color
	/// @return Dark electric blue color
	static hopp::color blue_electric_dark() { return { 82u, 104u, 121u }; }
	
	/// @brief Dark goldenrod color
	/// @return Dark goldenrod color
	static hopp::color goldenrod_dark() { return { 185u, 135u, 0u }; }
	
	/// @brief Dark grey color
	/// @return Dark grey color
	static hopp::color grey_dark() { return { 169u, 169u, 169u }; }
	
	/// @brief Dark green color
	/// @return Dark green color
	static hopp::color green_dark() { return { 0u, 50u, 31u }; }
	
	/// @brief Dark jungle green color
	/// @return Dark jungle green color
	static hopp::color green_jungle_dark() { return { 26u, 36u, 33u }; }
	
	/// @brief Dark khaki color
	/// @return Dark khaki color
	static hopp::color khaki_dark() { return { 190u, 184u, 100u }; }
	
	/// @brief Dark lava color
	/// @return Dark lava color
	static hopp::color lava_dark() { return { 72u, 60u, 49u }; }
	
	/// @brief Dark lavender color
	/// @return Dark lavender color
	static hopp::color lavender_dark() { return { 115u, 78u, 153u }; }
	
	/// @brief Dark magenta color
	/// @return Dark magenta color
	static hopp::color magenta_dark() { return { 140u, 0u, 142u }; }
	
	/// @brief Dark midnight blue color
	/// @return Dark midnight blue color
	static hopp::color blue_midnight_dark() { return { 0u, 50u, 104u }; }
	
	/// @brief Dark olive green color
	/// @return Dark olive green color
	static hopp::color green_olive_dark() { return { 85u, 107u, 41u }; }
	
	/// @brief Dark orange color
	/// @return Dark orange color
	static hopp::color orange_dark() { return { 255u, 142u, 0u }; }
	
	/// @brief Dark orchid color
	/// @return Dark orchid color
	static hopp::color orchid_dark() { return { 153u, 44u, 209u }; }
	
	/// @brief Dark pastel blue color
	/// @return Dark pastel blue color
	static hopp::color blue_pastel_dark() { return { 117u, 157u, 205u }; }
	
	/// @brief Dark pastel green color
	/// @return Dark pastel green color
	static hopp::color green_pastel_dark() { return { 0u, 193u, 41u }; }
	
	/// @brief Dark pastel purple color
	/// @return Dark pastel purple color
	static hopp::color purple_pastel_dark() { return { 150u, 109u, 218u }; }
	
	/// @brief Dark pastel red color
	/// @return Dark pastel red color
	static hopp::color red_pastel_dark() { return { 196u, 62u, 25u }; }
	
	/// @brief Dark pink color
	/// @return Dark pink color
	static hopp::color pink_dark() { return { 233u, 85u, 128u }; }
	
	/// @brief Dark powder blue color
	/// @return Dark powder blue color
	static hopp::color blue_dark_powder() { return { 0u, 47u, 157u }; }
	
	/// @brief Dark raspberry color
	/// @return Dark raspberry color
	static hopp::color raspberry_dark() { return { 136u, 38u, 88u }; }
	
	/// @brief Dark red color
	/// @return Dark red color
	static hopp::color red_dark() { return { 140u, 6u, 0u }; }
	
	/// @brief Dark salmon color
	/// @return Dark salmon color
	static hopp::color salmon_dark() { return { 234u, 151u, 119u }; }
	
	/// @brief Dark scarlet color
	/// @return Dark scarlet color
	static hopp::color scarlet_dark() { return { 87u, 4u, 24u }; }
	
	/// @brief Dark sea green color
	/// @return Dark sea green color
	static hopp::color green_sea_dark() { return { 142u, 188u, 140u }; }
	
	/// @brief Dark sienna color
	/// @return Dark sienna color
	static hopp::color sienna_dark() { return { 61u, 20u, 19u }; }
	
	/// @brief Dark slate blue color
	/// @return Dark slate blue color
	static hopp::color blue_slate_dark() { return { 71u, 59u, 142u }; }
	
	/// @brief Dark slate gray color
	/// @return Dark slate gray color
	static hopp::color gray_slate_dark() { return { 46u, 79u, 79u }; }
	
	/// @brief Dark spring green color
	/// @return Dark spring green color
	static hopp::color green_spring_dark() { return { 18u, 114u, 66u }; }
	
	/// @brief Dark tan color
	/// @return Dark tan color
	static hopp::color tan_dark() { return { 146u, 130u, 77u }; }
	
	/// @brief Dark tangerine color
	/// @return Dark tangerine color
	static hopp::color tangerine_dark() { return { 255u, 170u, 0u }; }
	
	/// @brief Dark taupe color
	/// @return Dark taupe color
	static hopp::color taupe_dark() { return { 72u, 60u, 49u }; }
	
	/// @brief Dark terra cotta color
	/// @return Dark terra cotta color
	static hopp::color terra_cotta_dark() { return { 206u, 80u, 91u }; }
	
	/// @brief Dark turquoise color
	/// @return Dark turquoise color
	static hopp::color turquoise_dark() { return { 0u, 205u, 210u }; }
	
	/// @brief Dark violet color
	/// @return Dark violet color
	static hopp::color violet_dark() { return { 148u, 0u, 216u }; }
	
	/// @brief Dartmouth green color
	/// @return Dartmouth green color
	static hopp::color green_dartmouth() { return { 0u, 105u, 59u }; }
	
	/// @brief Davy's grey color
	/// @return Davy's grey color
	static hopp::color grey_davy() { return { 85u, 85u, 85u }; }
	
	/// @brief Debian red color
	/// @return Debian red color
	static hopp::color red_debian() { return { 217u, 18u, 82u }; }
	
	/// @brief Deep carmine color
	/// @return Deep carmine color
	static hopp::color carmine_deep() { return { 170u, 35u, 61u }; }
	
	/// @brief Deep carmine pink color
	/// @return Deep carmine pink color
	static hopp::color pink_carmine_deep() { return { 241u, 53u, 50u }; }
	
	/// @brief Deep carrot orange color
	/// @return Deep carrot orange color
	static hopp::color orange_carrot_deep() { return { 235u, 107u, 29u }; }
	
	/// @brief Deep cerise color
	/// @return Deep cerise color
	static hopp::color cerise_deep() { return { 220u, 51u, 136u }; }
	
	/// @brief Deep champagne color
	/// @return Deep champagne color
	static hopp::color champagne_deep() { return { 251u, 215u, 161u }; }
	
	/// @brief Deep chestnut color
	/// @return Deep chestnut color
	static hopp::color chestnut_deep() { return { 186u, 79u, 69u }; }
	
	/// @brief Deep fuchsia color
	/// @return Deep fuchsia color
	static hopp::color fuchsia_deep() { return { 194u, 82u, 196u }; }
	
	/// @brief Deep jungle green color
	/// @return Deep jungle green color
	static hopp::color green_jungle_deep() { return { 0u, 75u, 73u }; }
	
	/// @brief Deep lilac color
	/// @return Deep lilac color
	static hopp::color lilac_deep() { return { 153u, 83u, 191u }; }
	
	/// @brief Deep magenta color
	/// @return Deep magenta color
	static hopp::color magenta_deep() { return { 205u, 0u, 208u }; }
	
	/// @brief Deep peach color
	/// @return Deep peach color
	static hopp::color peach_deep() { return { 255u, 204u, 161u }; }
	
	/// @brief Deep pink color
	/// @return Deep pink color
	static hopp::color pink_deep() { return { 255u, 24u, 149u }; }
	
	/// @brief Deep saffron color
	/// @return Deep saffron color
	static hopp::color saffron_deep() { return { 255u, 155u, 25u }; }
	
	/// @brief Deep sky blue color
	/// @return Deep sky blue color
	static hopp::color blue_sky_deep() { return { 0u, 189u, 255u }; }
	
	/// @brief Denim color
	/// @return Denim color
	static hopp::color denim() { return { 7u, 93u, 193u }; }
	
	/// @brief Desert color
	/// @return Desert color
	static hopp::color desert() { return { 194u, 155u, 103u }; }
	
	/// @brief Desert sand color
	/// @return Desert sand color
	static hopp::color sand_desert() { return { 238u, 202u, 173u }; }
	
	/// @brief Dim gray color
	/// @return Dim gray color
	static hopp::color gray_dim() { return { 105u, 105u, 105u }; }
	
	/// @brief Dodger blue color
	/// @return Dodger blue color
	static hopp::color blue_dodger() { return { 6u, 141u, 255u }; }
	
	/// @brief Dogwood rose color
	/// @return Dogwood rose color
	static hopp::color rose_dogwood() { return { 217u, 28u, 104u }; }
	
	/// @brief Dollar bill color
	/// @return Dollar bill color
	static hopp::color dollar_bill() { return { 132u, 188u, 94u }; }
	
	/// @brief Drab color
	/// @return Drab color
	static hopp::color drab() { return { 151u, 114u, 0u }; }
	
	/// @brief Duke blue color
	/// @return Duke blue color
	static hopp::color blue_duke() { return { 0u, 0u, 160u }; }
	
	/// @brief Earth yellow color
	/// @return Earth yellow color
	static hopp::color yellow_earth() { return { 226u, 170u, 87u }; }
	
	/// @brief Ecru color
	/// @return Ecru color
	static hopp::color ecru() { return { 195u, 179u, 124u }; }
	
	/// @brief Eggplant color
	/// @return Eggplant color
	static hopp::color eggplant() { return { 97u, 64u, 82u }; }
	
	/// @brief Eggshell color
	/// @return Eggshell color
	static hopp::color eggshell() { return { 240u, 234u, 213u }; }
	
	/// @brief Egyptian blue color
	/// @return Egyptian blue color
	static hopp::color blue_egyptian() { return { 6u, 47u, 170u }; }
	
	/// @brief Electric blue color
	/// @return Electric blue color
	static hopp::color blue_electric() { return { 121u, 248u, 255u }; }
	
	/// @brief Electric crimson color
	/// @return Electric crimson color
	static hopp::color crimson_electric() { return { 255u, 17u, 59u }; }
	
	/// @brief Electric cyan color
	/// @return Electric cyan color
	static hopp::color cyan_electric() { return { 0u, 254u, 255u }; }
	
	/// @brief Electric green color
	/// @return Electric green color
	static hopp::color green_electric() { return { 0u, 255u, 0u }; }
	
	/// @brief Electric indigo color
	/// @return Electric indigo color
	static hopp::color indigo_electric() { return { 109u, 0u, 255u }; }
	
	/// @brief Electric lavender color
	/// @return Electric lavender color
	static hopp::color lavender_electric() { return { 245u, 186u, 255u }; }
	
	/// @brief Electric lime color
	/// @return Electric lime color
	static hopp::color lime_electric() { return { 204u, 255u, 0u }; }
	
	/// @brief Electric purple color
	/// @return Electric purple color
	static hopp::color purple_electric() { return { 191u, 0u, 255u }; }
	
	/// @brief Electric ultramarine color
	/// @return Electric ultramarine color
	static hopp::color ultramarine_electric() { return { 58u, 0u, 255u }; }
	
	/// @brief Electric violet color
	/// @return Electric violet color
	static hopp::color violet_electric() { return { 142u, 0u, 255u }; }
	
	/// @brief Electric Yellow color
	/// @return electric Yellow color
	static hopp::color yellow_electric() { return { 255u, 255u, 0u }; }
	
	/// @brief Emerald color
	/// @return Emerald color
	static hopp::color emerald() { return { 76u, 200u, 115u }; }
	
	/// @brief Eton blue color
	/// @return Eton blue color
	static hopp::color blue_eton() { return { 149u, 200u, 160u }; }
	
	/// @brief Fallow color
	/// @return Fallow color
	static hopp::color fallow() { return { 194u, 155u, 103u }; }
	
	/// @brief Falu red color
	/// @return Falu red color
	static hopp::color red_falu() { return { 129u, 26u, 20u }; }
	
	/// @brief Fandango color
	/// @return Fandango color
	static hopp::color fandango() { return { 182u, 51u, 139u }; }
	
	/// @brief Fashion fuchsia color
	/// @return Fashion fuchsia color
	static hopp::color fuchsia_fashion() { return { 246u, 2u, 163u }; }
	
	/// @brief Fawn color
	/// @return Fawn color
	static hopp::color fawn() { return { 230u, 171u, 106u }; }
	
	/// @brief Feldgrau color
	/// @return Feldgrau color
	static hopp::color feldgrau() { return { 77u, 93u, 83u }; }
	
	/// @brief Fern green color
	/// @return Fern green color
	static hopp::color green_fern() { return { 78u, 121u, 62u }; }
	
	/// @brief Ferrari Red color
	/// @return Ferrari Red color
	static hopp::color red_ferrari() { return { 255u, 47u, 0u }; }
	
	/// @brief Field drab color
	/// @return Field drab color
	static hopp::color field_drab() { return { 109u, 85u, 22u }; }
	
	/// @brief Firebrick color
	/// @return Firebrick color
	static hopp::color firebrick() { return { 180u, 37u, 28u }; }
	
	/// @brief Fire engine red color
	/// @return Fire engine red color
	static hopp::color red_fire_engine() { return { 208u, 37u, 35u }; }
	
	/// @brief Flame color
	/// @return Flame color
	static hopp::color flame() { return { 228u, 90u, 15u }; }
	
	/// @brief Flamingo pink color
	/// @return Flamingo pink color
	static hopp::color pink_flamingo() { return { 253u, 143u, 172u }; }
	
	/// @brief Flavescent color
	/// @return Flavenscent color
	static hopp::color flavenscent() { return { 248u, 234u, 134u }; }
	
	/// @brief Flax color
	/// @return Flax color
	static hopp::color flax() { return { 239u, 221u, 122u }; }
	
	/// @brief Floral white color
	/// @return Floral white color
	static hopp::color white_floral() { return { 255u, 250u, 239u }; }
	
	/// @brief Fluorescent orange color
	/// @return Fluorescent orange color
	static hopp::color orange_fluorescent() { return { 255u, 193u, 0u }; }
	
	/// @brief Fluorescent pink color
	/// @return Fluorencent pink color
	static hopp::color pink_fluorescent() { return { 255u, 24u, 149u }; }
	
	/// @brief Fluorescent yellow color
	/// @return Fluorencent yellow color
	static hopp::color yellow_fluorescent() { return { 204u, 255u, 0u }; }
	
	/// @brief Folly color
	/// @return Folly color
	static hopp::color folly() { return { 255u, 16u, 76u }; }
	
	/// @brief Forest green (traditional) color
	/// @return Forest green (traditional) color
	static hopp::color green_forest_traditional() { return { 255u, 254u, 205u }; }
	
	/// @brief Forest green (web) color
	/// @return Forest green (web) color
	static hopp::color green_forest_web() { return { 30u, 139u, 13u }; }
	
	/// @brief French beige color
	/// @return French beige color
	static hopp::color beige_french() { return { 167u, 124u, 88u }; }
	
	/// @brief French blue color
	/// @return French blue color
	static hopp::color blue_french() { return { 0u, 112u, 190u }; }
	
	/// @brief French lilac color
	/// @return French lilac color
	static hopp::color lilac_french() { return { 134u, 95u, 144u }; }
	
	/// @brief French rose color
	/// @return French rose color
	static hopp::color rose_french() { return { 248u, 76u, 139u }; }
	
	/// @brief Fuchsia color
	/// @return Fuchsia color
	static hopp::color fuchsia() { return { 255u, 0u, 255u }; }
	
	/// @brief Fuchsia pink color
	/// @return Fuchsia pink color
	static hopp::color pink_fuchsia() { return { 255u, 117u, 255u }; }
	
	/// @brief Fulvous color
	/// @return Fulvous color
	static hopp::color fulvous() { return { 230u, 134u, 0u }; }
	
	/// @brief Fuzzy Wuzzy color
	/// @return Fuzzy Wuzzy color
	static hopp::color fuzzy_wuzzy() { return { 205u, 103u, 100u }; }
	
	/// @brief Gainsboro color
	/// @return Gainsboro color
	static hopp::color gainsboro() { return { 220u, 220u, 220u }; }
	
	/// @brief Gamboge color
	/// @return Gamboge color
	static hopp::color gamboge() { return { 230u, 157u, 0u }; }
	
	/// @brief Ghost white color
	/// @return Ghost white color
	static hopp::color white_ghost() { return { 248u, 248u, 255u }; }
	
	/// @brief Ginger color
	/// @return Ginger color
	static hopp::color ginger() { return { 177u, 102u, 0u }; }
	
	/// @brief Glaucous color
	/// @return Glaucous color
	static hopp::color glaucous() { return { 94u, 129u, 185u }; }
	
	/// @brief Gold (metallic) color
	/// @return Gold (metallic) color
	static hopp::color gold_metallic() { return { 213u, 176u, 30u }; }
	
	/// @brief Gold (web) color
	/// @return Gold (web) color
	static hopp::color gold_web() { return { 255u, 217u, 0u }; }
	
	/// @brief Golden brown color
	/// @return Golden brown color
	static hopp::color brown_golden() { return { 154u, 102u, 0u }; }
	
	/// @brief Golden poppy color
	/// @return Golden poppy color
	static hopp::color poppy_golden() { return { 253u, 196u, 0u }; }
	
	/// @brief Golden yellow color
	/// @return Golden yellow color
	static hopp::color yellow_golden() { return { 255u, 225u, 0u }; }
	
	/// @brief Goldenrod color
	/// @return Goldenrod color
	static hopp::color goldenrod() { return { 219u, 167u, 0u }; }
	
	/// @brief Granny Smith Apple color
	/// @return Granny Smith Apple color
	static hopp::color granny_smith_apple() { return { 167u, 228u, 156u }; }
	
	/// @brief Gray color
	/// @return Gray color
	static hopp::color gray() { return { 128u, 128u, 128u }; }
	
	/// @brief Gray (X11) color
	/// @return Gray (X11) color
	static hopp::color gray_x11() { return { 190u, 190u, 190u }; }
	
	/// @brief Gray-asparagus color
	/// @return Gray-asparagus color
	static hopp::color gray_asparagus() { return { 70u, 89u, 68u }; }
	
	/// @brief Green (X11) color
	/// @return Green (X11) color
	static hopp::color green_x11() { return { 0u, 255u, 0u }; }
	
	/// @brief Green (HTML/CSS) color
	/// @return Green (HTML/CSS) color
	static hopp::color green_html_css() { return { 0u, 128u, 0u }; }
	
	/// @brief Green (Munsell) color
	/// @return Green (Munsell) color
	static hopp::color green_munsell() { return { 0u, 168u, 116u }; }
	
	/// @brief Green (NCS) color
	/// @return Green (NCS) color
	static hopp::color green_ncs() { return { 0u, 159u, 104u }; }
	
	/// @brief Green (pigment) color
	/// @return Green (pigment) color
	static hopp::color green_pigment() { return { 0u, 165u, 73u }; }
	
	/// @brief Green (RYB) color
	/// @return Green (RYB) color
	static hopp::color green_ryb() { return { 101u, 177u, 28u }; }
	
	/// @brief Green-yellow color
	/// @return Green-yellow color
	static hopp::color green_yellow() { return { 172u, 255u, 0u }; }
	
	/// @brief Grullo color
	/// @return Grullo color
	static hopp::color grullo() { return { 169u, 154u, 133u }; }
	
	/// @brief Guppie green color
	/// @return Guppie green color
	static hopp::color green_guppie() { return { 0u, 255u, 116u }; }
	
	/// @brief Halaya ube color
	/// @return Halaya ube color
	static hopp::color ube_halaya() { return { 103u, 56u, 85u }; }
	
	/// @brief Han blue color
	/// @return Han blue color
	static hopp::color blue_han() { return { 65u, 105u, 211u }; }
	
	/// @brief Han purple color
	/// @return Han purple color
	static hopp::color purple_han() { return { 79u, 0u, 255u }; }
	
	/// @brief Hansa yellow color
	/// @return Hansa yellow color
	static hopp::color yellow_hansa() { return { 234u, 215u, 95u }; }
	
	/// @brief Harlequin color
	/// @return Harlequin color
	static hopp::color harlequin() { return { 55u, 255u, 0u }; }
	
	/// @brief Harvard crimson color
	/// @return Harvard crimson color
	static hopp::color crimson_harvard() { return { 203u, 12u, 10u }; }
	
	/// @brief Harvest Gold color
	/// @return Harvest Gold color
	static hopp::color gold_harvest() { return { 219u, 147u, 0u }; }
	
	/// @brief Heart Gold color
	/// @return Heart Gold color
	static hopp::color gold_heart() { return { 128u, 129u, 0u }; }
	
	/// @brief Heliotrope color
	/// @return Heliotrope color
	static hopp::color heliotrope() { return { 224u, 112u, 255u }; }
	
	/// @brief Hollywood cerise color
	/// @return Hollywood cerise color
	static hopp::color cerise_hollywood() { return { 246u, 2u, 163u }; }
	
	/// @brief Honeydew color
	/// @return Honeydew color
	static hopp::color honeydew() { return { 240u, 255u, 239u }; }
	
	/// @brief Hooker's green color
	/// @return Hooker's green color
	static hopp::color green_hooker() { return { 0u, 112u, 0u }; }
	
	/// @brief Hot magenta color
	/// @return Hot magenta color
	static hopp::color magenta_hot() { return { 255u, 25u, 210u }; }
	
	/// @brief Hot pink color
	/// @return Hot pink color
	static hopp::color pink_hot() { return { 255u, 105u, 182u }; }
	
	/// @brief Hunter green color
	/// @return Hunter green color
	static hopp::color green_hunter() { return { 52u, 94u, 57u }; }
	
	/// @brief Iceberg color
	/// @return Iceberg color
	static hopp::color iceberg() { return { 111u, 165u, 212u }; }
	
	/// @brief Icterine color
	/// @return Icterine color
	static hopp::color icterine() { return { 253u, 248u, 72u }; }
	
	/// @brief Inchworm color
	/// @return Inchworm color
	static hopp::color inchworm() { return { 178u, 237u, 75u }; }
	
	/// @brief India green color
	/// @return India green color
	static hopp::color green_india() { return { 12u, 137u, 0u }; }
	
	/// @brief Indian red color
	/// @return Indian red color
	static hopp::color red_indian() { return { 207u, 93u, 90u }; }
	
	/// @brief Indian yellow color
	/// @return Indian yellow color
	static hopp::color yellow_indian() { return { 228u, 169u, 77u }; }
	
	/// @brief Indigo (dye) color
	/// @return Indigo (dye) color
	static hopp::color indigo_dye() { return { 0u, 64u, 108u }; }
	
	/// @brief Indigo (web) color
	/// @return Indigo (web) color
	static hopp::color indigo_web() { return { 75u, 0u, 133u }; }
	
	/// @brief International Klein Blue color
	/// @return International Klein Blue color
	static hopp::color blue_klein_international() { return { 0u, 42u, 171u }; }
	
	/// @brief International orange color
	/// @return International orange color
	static hopp::color orange_international() { return { 255u, 83u, 0u }; }
	
	/// @brief Iris color
	/// @return Iris color
	static hopp::color iris() { return { 88u, 75u, 212u }; }
	
	/// @brief Isabelline color
	/// @return Isabelline color
	static hopp::color isabelline() { return { 244u, 240u, 236u }; }
	
	/// @brief Islamic green color
	/// @return Islamic green color
	static hopp::color green_islamic() { return { 0u, 145u, 0u }; }
	
	/// @brief Ivory color
	/// @return Ivory color
	static hopp::color ivory() { return { 255u, 255u, 239u }; }
	
	/// @brief Jade color
	/// @return Jade color
	static hopp::color jade() { return { 0u, 168u, 103u }; }
	
	/// @brief Jasper color
	/// @return Jasper color
	static hopp::color jasper() { return { 217u, 62u, 58u }; }
	
	/// @brief Jazzberry jam color
	/// @return Jazzberry jam color
	static hopp::color jazzberry_jam() { return { 166u, 13u, 95u }; }
	
	/// @brief Jonquil color
	/// @return Jonquil color
	static hopp::color jonquil() { return { 251u, 219u, 78u }; }
	
	/// @brief June bud color
	/// @return June bud color
	static hopp::color june_bud() { return { 189u, 219u, 70u }; }
	
	/// @brief Jungle green color
	/// @return Jungle green color
	static hopp::color green_jungle() { return { 34u, 171u, 133u }; }
	
	/// @brief Kelly green color
	/// @return Kelly green color
	static hopp::color green_kelly() { return { 73u, 188u, 0u }; }
	
	/// @brief Khaki (HTML/CSS) color
	/// @return Khaki (HTML/CSS) color
	static hopp::color khaki_html_css() { return { 196u, 177u, 143u }; }
	
	/// @brief Khaki (X11) color
	/// @return Khaki (X11) color
	static hopp::color khaki_x11() { return { 241u, 231u, 132u }; }
	
	/// @brief La Salle Green color
	/// @return La Salle Green color
	static hopp::color green_la_salle() { return { 0u, 120u, 41u }; }
	
	/// @brief Languid lavender color
	/// @return Languid lavender color
	static hopp::color lavender() { return { 214u, 202u, 222u }; }
	
	/// @brief Lapis lazuli color
	/// @return Lapis lazuli color
	static hopp::color lapis_lazuli() { return { 34u, 95u, 159u }; }
	
	/// @brief Laser Lemon color
	/// @return Laser Lemon color
	static hopp::color lemon_lazer() { return { 255u, 255u, 0u }; }
	
	/// @brief Lava color
	/// @return Lava color
	static hopp::color lava() { return { 209u, 24u, 24u }; }
	
	/// @brief Lavender (floral) color
	/// @return Lavender (floral) color
	static hopp::color lavender_floral() { return { 181u, 124u, 224u }; }
	
	/// @brief Lavender (web) color
	/// @return Lavender (web) color
	static hopp::color lavender_web() { return { 230u, 230u, 251u }; }
	
	/// @brief Lavender blue color
	/// @return Lavender blue color
	static hopp::color blue_lavender() { return { 204u, 203u, 255u }; }
	
	/// @brief Lavender blush color
	/// @return Lavender blush color
	static hopp::color blush_lavender() { return { 255u, 240u, 245u }; }
	
	/// @brief Lavender gray color
	/// @return Lavender gray color
	static hopp::color gray_lavender() { return { 196u, 195u, 209u }; }
	
	/// @brief Lavender indigo color
	/// @return Lavender indigo color
	static hopp::color indigo_lavender() { return { 148u, 83u, 240u }; }
	
	/// @brief Lavender magenta color
	/// @return Lavender magenta color
	static hopp::color magenta_lavender() { return { 239u, 129u, 242u }; }
	
	/// @brief Lavender mist color
	/// @return Lavender mist color
	static hopp::color mist_lavender() { return { 230u, 230u, 251u }; }
	
	/// @brief Lavender pink color
	/// @return Lavender pink color
	static hopp::color pink_lavender() { return { 252u, 174u, 211u }; }
	
	/// @brief Lavender purple color
	/// @return Lavender purple color
	static hopp::color purple_lavender() { return { 150u, 122u, 185u }; }
	
	/// @brief Lavender rose color
	/// @return Lavender rose color
	static hopp::color rose_lavender() { return { 252u, 160u, 229u }; }
	
	/// @brief Lawn green color
	/// @return Lawn green color
	static hopp::color green_lawn() { return { 122u, 253u, 0u }; }
	
	/// @brief Lemon color
	/// @return Lemon color
	static hopp::color lemon() { return { 255u, 249u, 0u }; }
	
	/// @brief Lemon chiffon color
	/// @return Lemon chiffon color
	static hopp::color lemon_chiffon() { return { 255u, 251u, 202u }; }
	
	/// @brief Ligth apricot color
	/// @return Light apricot color
	static hopp::color apricot_light() { return { 254u, 214u, 174u }; }
	
	/// @brief Light blue color
	/// @return Light blue color
	static hopp::color blue_light() { return { 172u, 216u, 231u }; }
	
	/// @brief Light brown color
	/// @return Light brown color
	static hopp::color brown_light() { return { 182u, 102u, 8u }; }
	
	/// @brief Light carmine pink color
	/// @return Light carmine pink color
	static hopp::color pink_carmine_light() { return { 232u, 104u, 112u }; }
	
	/// @brief Light coral color
	/// @return Light coral color
	static hopp::color coral_light() { return { 242u, 129u, 126u }; }
	
	/// @brief Light cornflower blue color
	/// @return Light cornflower blue color
	static hopp::color blue_cornflower_light() { return { 145u, 203u, 236u }; }
	
	/// @brief Light cyan color
	/// @return Light cyan color
	static hopp::color cyan_light() { return { 223u, 255u, 255u }; }
	
	/// @brief Light fuchsia pink color
	/// @return Light fuchsia pink color
	static hopp::color pink_fuchsia_light() { return { 250u, 131u, 243u }; }
	
	/// @brief Light goldenrod yellow color
	/// @return Light goldenrod yellow color
	static hopp::color yellow_golden_light() { return { 250u, 251u, 207u }; }
	
	/// @brief Light gray color
	/// @return Light gray color
	static hopp::color gray_light() { return { 211u, 211u, 211u }; }
	
	/// @brief Light green color
	/// @return Light green color
	static hopp::color green_light() { return { 142u, 239u, 137u }; }
	
	/// @brief Light khaki color
	/// @return Light khaki color
	static hopp::color khaki_light() { return { 241u, 231u, 132u }; }
	
	/// @brief Light mauve color
	/// @return Light mauve color
	static hopp::color mauve_light() { return { 220u, 207u, 255u }; }
	
	/// @brief Light pastel purple color
	/// @return Light pastel purple color
	static hopp::color purple_pastel_light() { return { 177u, 155u, 220u }; }
	
	/// @brief Light pink color
	/// @return Light pink color
	static hopp::color pink_light() { return { 255u, 182u, 193u }; }
	
	/// @brief Light salmon color
	/// @return Light salmon color
	static hopp::color salmon_light() { return { 255u, 161u, 117u }; }
	
	/// @brief Light salmon pink color
	/// @return Light salmon pink color
	static hopp::color pink_salmon_light() { return { 255u, 154u, 152u }; }
	
	/// @brief Light sea green color
	/// @return Light sea green color
	static hopp::color green_sea_light() { return { 18u, 178u, 170u }; }
	
	/// @brief Light sky blue color
	/// @return Light sky blue color
	static hopp::color blue_sky_light() { return { 133u, 205u, 237u }; }
	
	/// @brief Light slate gray color
	/// @return Light slate gray color
	static hopp::color gray_slate_light() { return { 118u, 136u, 154u }; }
	
	/// @brief Light taupe color
	/// @return Light taupe color
	static hopp::color taupe_light() { return { 180u, 140u, 106u }; }
	
	/// @brief Light Thulian pink color
	/// @return Light Thulian pink color
	static hopp::color pink_thulian_light() { return { 231u, 143u, 173u }; }
	
	/// @brief Light yellow color
	/// @return Light yellow color
	static hopp::color yellow_light() { return { 255u, 255u, 236u }; }
	
	/// @brief Lilac color
	/// @return Lilac color
	static hopp::color lilac() { return { 200u, 162u, 202u }; }
	
	/// @brief Lime (wheel) color
	/// @return Lime (wheel) color
	static hopp::color lime_wheel() { return { 191u, 255u, 0u }; }
	
	/// @brief Lime (X11) color
	/// @return Lime (X11) color
	static hopp::color lime_x11() { return { 0u, 255u, 0u }; }
	
	/// @brief Lime green color
	/// @return Lime green color
	static hopp::color green_lime() { return { 44u, 206u, 13u }; }
	
	/// @brief Lincoln green color
	/// @return Lincoln green color
	static hopp::color green_lincoln() { return { 23u, 89u, 0u }; }
	
	/// @brief Linen color
	/// @return Linen color
	static hopp::color linen() { return { 250u, 240u, 229u }; }
	
	/// @brief Liver color
	/// @return Liver color
	static hopp::color liver() { return { 83u, 75u, 79u }; }
	
	/// @brief Lust color
	/// @return Lust color
	static hopp::color lust() { return { 232u, 38u, 20u }; }
	
	/// @brief Macaroni and Cheese color
	/// @return Macaroni and Cheese color
	static hopp::color macaroni_and_cheese() { return { 255u, 190u, 131u }; }
	
	/// @brief Magenta color
	/// @return Magenta color
	static hopp::color magenta() { return { 255u, 0u, 255u }; }
	
	/// @brief Magenta (dye) color
	/// @return Magenta (dye) color
	static hopp::color magenta_dye() { return { 204u, 32u, 124u }; }
	
	/// @brief Magenta (process) color
	/// @return Magenta (process) color
	static hopp::color magenta_process() { return { 255u, 8u, 146u }; }
	
	/// @brief Magic mint color
	/// @return Magic mint color
	static hopp::color mint_magic() { return { 169u, 240u, 208u }; }
	
	/// @brief Magnolia color
	/// @return Magnolia color
	static hopp::color magnolia() { return { 248u, 244u, 255u }; }
	
	/// @brief Mahogany color
	/// @return Mahogany color
	static hopp::color mahogany() { return { 194u, 66u, 0u }; }
	
	/// @brief Maize color
	/// @return Maize color
	static hopp::color maize() { return { 252u, 237u, 73u }; }
	
	/// @brief Majorelle Blue color
	/// @return Majorelle Blue color
	static hopp::color blue_majorelle() { return { 94u, 75u, 225u }; }
	
	/// @brief Malachite color
	/// @return Malachite color
	static hopp::color malachite() { return { 0u, 219u, 65u }; }
	
	/// @brief Manatee color
	/// @return Manatee color
	static hopp::color manatee() { return { 151u, 154u, 171u }; }
	
	/// @brief Mango Tango color
	/// @return Mango Tango color
	static hopp::color mango_tango() { return { 255u, 132u, 56u }; }
	
	/// @brief Maroon (HTML/CSS) color
	/// @return Maroon (HTML/CSS) color
	static hopp::color maroon_html_css() { return { 129u, 5u, 0u }; }
	
	/// @brief Maroon (X11) color
	/// @return Maroon (X11) color
	static hopp::color maroon_x11() { return { 177u, 49u, 96u }; }
	
	/// @brief Mauve color
	/// @return Mauve color
	static hopp::color mauve() { return { 224u, 175u, 255u }; }
	
	/// @brief Mauve taupe color
	/// @return Mauve taupe color
	static hopp::color taupe_mauve() { return { 146u, 95u, 109u }; }
	
	/// @brief Mauvelous color
	/// @return Mauvelous color
	static hopp::color mauvelous() { return { 240u, 153u, 170u }; }
	
	/// @brief Maya blue color
	/// @return Maya blue color
	static hopp::color blue_maya() { return { 112u, 193u, 254u }; }
	
	/// @brief Meat brown color
	/// @return Meat brown color
	static hopp::color brown_meat() { return { 230u, 184u, 34u }; }
	
	/// @brief Medium aquamarine color
	/// @return Medium aquamarine color
	static hopp::color aquamarine_medium() { return { 98u, 221u, 167u }; }
	
	/// @brief Medium blue color
	/// @return Medium blue color
	static hopp::color blue_medium() { return { 0u, 0u, 210u }; }
	
	/// @brief Medium candy apple red color
	/// @return Medium candy apple red color
	static hopp::color red_candy_apple_medium() { return { 226u, 6u, 44u }; }
	
	/// @brief Medium carmine color
	/// @return Medium carmine color
	static hopp::color carmine_medium() { return { 175u, 64u, 53u }; }
	
	/// @brief Medium champagne color
	/// @return Medium champagne color
	static hopp::color champagne_medium() { return { 243u, 229u, 171u }; }
	
	/// @brief Medium electric blue color
	/// @return Medium electric blue color
	static hopp::color blue_electric_medium() { return { 3u, 80u, 150u }; }
	
	/// @brief Medium jungle green color
	/// @return Medium jungle green color
	static hopp::color green_jungle_medium() { return { 28u, 53u, 45u }; }
	
	/// @brief Medium lavender magenta color
	/// @return Medium lavender magenta color
	static hopp::color magenta_lavender_medium() { return { 221u, 160u, 221u }; }
	
	/// @brief Medium orchid color
	/// @return Medium orchid color
	static hopp::color orchid_medium() { return { 186u, 85u, 211u }; }
	
	/// @brief Medium Persian blue color
	/// @return Medium Persian blue color
	static hopp::color blue_persian_medium() { return { 0u, 103u, 165u }; }
	
	/// @brief Medium purple color
	/// @return Medium purple color
	static hopp::color purple_medium() { return { 147u, 112u, 219u }; }
	
	/// @brief Medium red-violet color
	/// @return Medium red-violet color
	static hopp::color red_violet_medium() { return { 187u, 51u, 133u }; }
	
	/// @brief Medium sea green color
	/// @return Medium sea green color
	static hopp::color green_sea_medium() { return { 60u, 179u, 113u }; }
	
	/// @brief Medium slate blue color
	/// @return Medium slate blue color
	static hopp::color blue_slate_medium() { return { 123u, 104u, 238u }; }
	
	/// @brief Medium spring bud color
	/// @return Medium spring bud color
	static hopp::color spring_bud_medium() { return { 201u, 220u, 135u }; }
	
	/// @brief Medium spring green color
	/// @return Medium spring green color
	static hopp::color green_spring_medium() { return { 0u, 250u, 154u }; }
	
	/// @brief Medium taupe color
	/// @return Medium taupe color
	static hopp::color taupe_medium() { return { 103u, 76u, 71u }; }
	
	/// @brief Medium teal blue color
	/// @return Medium teal blue color
	static hopp::color blue_teal_medium() { return { 0u, 84u, 180u }; }
	
	/// @brief Medium turquoise color
	/// @return Medium turquoise color
	static hopp::color turquoise_medium() { return { 72u, 209u, 204u }; }
	
	/// @brief Medium violet-red color
	/// @return Medium violet-red color
	static hopp::color violet_red_medium() { return { 199u, 21u, 133u }; }
	
	/// @brief Melon color
	/// @return Melon color
	static hopp::color melon() { return { 253u, 188u, 180u }; }
	
	/// @brief Midnight blue color
	/// @return Midnight blue color
	static hopp::color blue_midnight() { return { 25u, 25u, 112u }; }
	
	/// @brief Midnight green (eagle green) color
	/// @return Midnight green (eagle green) color
	static hopp::color green_midnight() { return { 0u, 73u, 83u }; }
	
	/// @brief Mikado yellow color
	/// @return Mikado yellow color
	static hopp::color yellow_mikado() { return { 255u, 196u, 12u }; }
	
	/// @brief Mint color
	/// @return Mint color
	static hopp::color mint() { return { 62u, 180u, 137u }; }
	
	/// @brief Mint cream color
	/// @return Mint cream color
	static hopp::color mint_cream() { return { 245u, 255u, 250u }; }
	
	/// @brief Mint green color
	/// @return Mint green color
	static hopp::color mint_green() { return { 152u, 255u, 152u }; }
	
	/// @brief Misty rose color
	/// @return Misty rose color
	static hopp::color rose_misty() { return { 255u, 228u, 225u }; }
	
	/// @brief Moccasin color
	/// @return Moccasin color
	static hopp::color moccasin() { return { 250u, 235u, 215u }; }
	
	/// @brief Mode beige color
	/// @return Mode beige color
	static hopp::color beige_mode() { return { 150u, 113u, 23u }; }
	
	/// @brief Moonstone blue color
	/// @return Moonstone blue color
	static hopp::color blue_moonstone() { return { 115u, 169u, 194u }; }
	
	/// @brief Mordant red 19 color
	/// @return Mordant red 19 color
	static hopp::color red_mordant_19() { return { 174u, 12u, 0u }; }
	
	/// @brief Moss green color
	/// @return Moss green color
	static hopp::color green_moss() { return { 173u, 223u, 173u }; }
	
	/// @brief Mountain Meadow color
	/// @return Mountain Meadow color
	static hopp::color mountain_meadow() { return { 48u, 186u, 143u }; }
	
	/// @brief Mountbatten pink color
	/// @return Mountbatten pink color
	static hopp::color pink_mountbatten() { return { 153u, 122u, 141u }; }
	
	/// @brief Mulberry color
	/// @return Mulberry color
	static hopp::color mulberry() { return { 197u, 75u, 140u }; }
	
	/// @brief Mustard color
	/// @return Mustard color
	static hopp::color mustard() { return { 255u, 219u, 88u }; }
	
	/// @brief Myrtle color
	/// @return Myrtle color
	static hopp::color myrtle() { return { 33u, 66u, 30u }; }
	
	/// @brief MSU green color
	/// @return MSU green color
	static hopp::color green_msu() { return { 24u, 69u, 59u }; }
	
	/// @brief Nadeshiko pink color
	/// @return Nadeshiko pink color
	static hopp::color pink_madeshiko() { return { 246u, 173u, 198u }; }
	
	/// @brief Napier green color
	/// @return Napier green color
	static hopp::color green_napier() { return { 42u, 128u, 0u }; }
	
	/// @brief Naples yellow color
	/// @return Naples yellow color
	static hopp::color yellow_naples() { return { 250u, 218u, 94u }; }
	
	/// @brief Navajo white color
	/// @return Navajo white color
	static hopp::color white_navajo() { return { 255u, 254u, 205u }; }
	
	/// @brief Navy blue color
	/// @return Navy blue color
	static hopp::color blue_navy() { return { 0u, 0u, 128u }; }
	
	/// @brief Neon Carrot color
	/// @return Neon Carrot color
	static hopp::color carrot_neon() { return { 255u, 163u, 67u }; }
	
	/// @brief Neon fuchsia color
	/// @return Neon fuchsia color
	static hopp::color fuchsia_neon() { return { 254u, 89u, 194u }; }
	
	/// @brief Neon green color
	/// @return Neon green color
	static hopp::color green_neon() { return { 57u, 255u, 21u }; }
	
	/// @brief Non-photo blue color
	/// @return Non-photo blue color
	static hopp::color blue_non_photo() { return { 164u, 221u, 237u }; }
	
	/// @brief Ocean Boat Blue color
	/// @return Ocean Boat Blue color
	static hopp::color blue_ocean_boat() { return { 0u, 119u, 190u }; }
	
	/// @brief Ochre color
	/// @return Ochre color
	static hopp::color ochre() { return { 204u, 119u, 34u }; }
	
	/// @brief Office green color
	/// @return Office green color
	static hopp::color green_office() { return { 0u, 128u, 0u }; }
	
	/// @brief Old gold color
	/// @return Old gold color
	static hopp::color gold_old() { return { 207u, 181u, 60u }; }
	
	/// @brief Old lace color
	/// @return Old lace color
	static hopp::color lace_old() { return { 253u, 245u, 230u }; }
	
	/// @brief Old lavender color
	/// @return Old lavender color
	static hopp::color lavender_old() { return { 121u, 104u, 120u }; }
	
	/// @brief Old mauve color
	/// @return Old mauve color
	static hopp::color mauve_old() { return { 103u, 49u, 71u }; }
	
	/// @brief Old rose color
	/// @return Old rose color
	static hopp::color rose_old() { return { 192u, 128u, 129u }; }
	
	/// @brief Olive color
	/// @return Olive color
	static hopp::color olive() { return { 128u, 128u, 0u }; }
	
	/// @brief Olive Drab (web) color
	/// @return Olive Drab (web) color
	static hopp::color olive_drab_web() { return { 107u, 142u, 35u }; }
	
	/// @brief Olive Drab #7 color
	/// @return Olive Drab #7 color
	static hopp::color olive_drab_7() { return { 60u, 52u, 31u }; }
	
	/// @brief Olivine color
	/// @return Olivine color
	static hopp::color olivine() { return { 154u, 185u, 115u }; }
	
	/// @brief Onyx color
	/// @return Onyx color
	static hopp::color onyx() { return { 15u, 15u, 15u }; }
	
	/// @brief Opera mauve color
	/// @return Opera mauve color
	static hopp::color mauve_opera() { return { 183u, 132u, 205u }; }
	
	/// @brief Orange (wheel) color
	/// @return Orange (wheel) color
	static hopp::color orange_wheel() { return { 255u, 127u, 1u }; }
	
	/// @brief Orange (RYB) color
	/// @return Orange (RYB) color
	static hopp::color orange_ryb() { return { 251u, 153u, 2u }; }
	
	/// @brief Orange (web) color
	/// @return Orange (web) color
	static hopp::color orange_web() { return { 255u, 165u, 0u }; }
	
	/// @brief Orange peel color
	/// @return Orange peel color
	static hopp::color orange_peel() { return { 255u, 159u, 0u }; }
	
	/// @brief Orange-red color
	/// @return Orange-red color
	static hopp::color orange_red() { return { 255u, 69u, 0u }; }
	
	/// @brief Orchid color
	/// @return Orchid color
	static hopp::color orchid() { return { 218u, 112u, 214u }; }
	
	/// @brief Otter brown color
	/// @return Otter brown color
	static hopp::color brown_otter() { return { 101u, 67u, 32u }; }
	
	/// @brief Outer Space color
	/// @return Outer Space color
	static hopp::color outer_space() { return { 65u, 74u, 76u }; }
	
	/// @brief Outrageous Orange color
	/// @return Outrageous Orange color
	static hopp::color orange_outrageous() { return { 255u, 110u, 74u }; }
	
	/// @brief Oxford Blue color
	/// @return Oxford Blue color
	static hopp::color blue_oxford() { return { 0u, 33u, 71u }; }
	
	/// @brief OU Crimson Red color
	/// @return Ou Crimson Red color
	static hopp::color red_ou_crimson() { return { 153u, 7u, 0u }; }
	
	/// @brief Pakistan green color
	/// @return Pakistan green color
	static hopp::color green_pakistan() { return { 0u, 102u, 0u }; }
	
	/// @brief Palatinate blue color
	/// @return Palatinate blue color
	static hopp::color blue_palatinate() { return { 39u, 59u, 226u }; }
	
	/// @brief Palatinate purple color
	/// @return Palatinate purple color
	static hopp::color purple_palatinate() { return { 104u, 40u, 96u }; }
	
	/// @brief Pale aqua color
	/// @return Pale aqua color
	static hopp::color aqua_pale() { return { 188u, 212u, 230u }; }
	
	/// @brief Pale blue color
	/// @return Pale blue color
	static hopp::color blue_pale() { return { 175u, 238u, 238u }; }
	
	/// @brief Pale brown color
	/// @return Pale brown color
	static hopp::color brown_pale() { return { 152u, 118u, 84u }; }
	
	/// @brief Pale carmine color
	/// @return Pale carmine color
	static hopp::color carmine_pale() { return { 175u, 64u, 53u }; }
	
	/// @brief Pale cerulean color
	/// @return Pale cerulean color
	static hopp::color cerulean_pale() { return { 155u, 196u, 226u }; }
	
	/// @brief Pale chestnut color
	/// @return Pale chestnut color
	static hopp::color chestnut_pale() { return { 221u, 173u, 175u }; }
	
	/// @brief Pale copper color
	/// @return Pale copper color
	static hopp::color copper_pale() { return { 218u, 138u, 103u }; }
	
	/// @brief Pale cornflower blue color
	/// @return Pale cornflower blue color
	static hopp::color blue_cornflower_pale() { return { 171u, 205u, 239u }; }
	
	/// @brief Pale gold color
	/// @return Pale gold color
	static hopp::color gold_pale() { return { 230u, 190u, 138u }; }
	
	/// @brief Pale goldenrod color
	/// @return Pale goldenrod color
	static hopp::color goldenrod_pale() { return { 239u, 232u, 170u }; }
	
	/// @brief Pale green color
	/// @return Pale green color
	static hopp::color green_pale() { return { 152u, 251u, 152u }; }
	
	/// @brief Pale magenta color
	/// @return Pale magenta color
	static hopp::color magenta_pale() { return { 249u, 132u, 229u }; }
	
	/// @brief Pale pink color
	/// @return Pale pink color
	static hopp::color pink_pale() { return { 250u, 218u, 221u }; }
	
	/// @brief Pale plum color
	/// @return Pale plum color
	static hopp::color plum_pale() { return { 221u, 160u, 221u }; }
	
	/// @brief Pale red-violet color
	/// @return Pale red-violet color
	static hopp::color red_violet_pale() { return { 219u, 112u, 147u }; }
	
	/// @brief Pale robin egg blue color
	/// @return Pale robin egg blue color
	static hopp::color blue_robin_egg_pale() { return { 150u, 222u, 209u }; }
	
	/// @brief Pale silver color
	/// @return Pale silver color
	static hopp::color silver_pale() { return { 201u, 192u, 187u }; }
	
	/// @brief Pale spring bud color
	/// @return Pale spring bud color
	static hopp::color spring_bud_pale() { return { 236u, 235u, 189u }; }
	
	/// @brief Pale taupe color
	/// @return Pale taupe color
	static hopp::color taupe_pale() { return { 188u, 152u, 126u }; }
	
	/// @brief Pale violet-red color
	/// @return Pale violet-red color
	static hopp::color violet_red_pale() { return { 219u, 112u, 147u }; }
	
	/// @brief Pansy purple color
	/// @return Pansy purple color
	static hopp::color purple_pansy() { return { 120u, 23u, 74u }; }
	
	/// @brief Papaya whip color
	/// @return Papaya whip color
	static hopp::color papaya_whip() { return { 255u, 239u, 213u }; }
	
	/// @brief Paris Green color
	/// @return Paris Green color
	static hopp::color green_paris() { return { 80u, 200u, 120u }; }
	
	/// @brief Pastel blue color
	/// @return Pastel blue color
	static hopp::color blue_pastel() { return { 174u, 198u, 207u }; }
	
	/// @brief Pastel brown color
	/// @return Pastel brown color
	static hopp::color brown_pastel() { return { 131u, 105u, 83u }; }
	
	/// @brief Pastel gray color
	/// @return Pastel gray color
	static hopp::color gray_pastel() { return { 207u, 207u, 196u }; }
	
	/// @brief Pastel green color
	/// @return Pastel green color
	static hopp::color green_pastel() { return { 119u, 221u, 119u }; }
	
	/// @brief Pastel magenta color
	/// @return Pastel magenta color
	static hopp::color magenta_pastel() { return { 244u, 154u, 194u }; }
	
	/// @brief Pastel orange color
	/// @return Pastel orange color
	static hopp::color orange_pastel() { return { 255u, 179u, 71u }; }
	
	/// @brief Pastel pink color
	/// @return Pastel pink color
	static hopp::color pink_pastel() { return { 255u, 209u, 220u }; }
	
	/// @brief Pastel purple color
	/// @return Pastel purple color
	static hopp::color purple_pastel() { return { 179u, 158u, 181u }; }
	
	/// @brief Pastel red color
	/// @return Pastel red color
	static hopp::color red_pastel() { return { 255u, 105u, 97u }; }
	
	/// @brief Pastel violet color
	/// @return Pastel violet color
	static hopp::color violet_pastel() { return { 203u, 153u, 201u }; }
	
	/// @brief Pastel yellow color
	/// @return Pastel yellow color
	static hopp::color yellow_pastel() { return { 253u, 253u, 150u }; }
	
	/// @brief Patriarch color
	/// @return Patriarch color
	static hopp::color patriarch() { return { 128u, 0u, 128u }; }
	
	/// @brief Payne's grey color
	/// @return Payne's grey color
	static hopp::color grey_payne() { return { 64u, 64u, 79u }; }
	
	/// @brief Peach color
	/// @return Peach color
	static hopp::color peach() { return { 255u, 229u, 180u }; }
	
	/// @brief Peach-orange color
	/// @return Peach-orange color
	static hopp::color peach_orange() { return { 255u, 204u, 153u }; }
	
	/// @brief Peach puff color
	/// @return Peach puff color
	static hopp::color peach_puff() { return { 255u, 218u, 185u }; }
	
	/// @brief Peach-yellow color
	/// @return Peach-yellow color
	static hopp::color peach_yellow() { return { 250u, 223u, 174u }; }
	
	/// @brief Pear color
	/// @return Pear color
	static hopp::color pear() { return { 209u, 226u, 48u }; }
	
	/// @brief Pearl color
	/// @return Pearl color
	static hopp::color pearl() { return { 240u, 234u, 214u }; }
	
	/// @brief Peridot color
	/// @return Peridot color
	static hopp::color peridot() { return { 230u, 226u, 0u }; }
	
	/// @brief Periwinkle color
	/// @return Periwinkle color
	static hopp::color periwinkle() { return { 204u, 204u, 255u }; }
	
	/// @brief Persian blue color
	/// @return Persian blue color
	static hopp::color blue_persian() { return { 28u, 57u, 187u }; }
	
	/// @brief Persian green color
	/// @return Persian green color
	static hopp::color green_persian() { return { 0u, 166u, 147u }; }
	
	/// @brief Persian indigo color
	/// @return Persian indigo color
	static hopp::color indigo_persian() { return { 50u, 18u, 122u }; }
	
	/// @brief Persian orange color
	/// @return Persian orange color
	static hopp::color orange_persian() { return { 217u, 144u, 88u }; }
	
	/// @brief Peru color
	/// @return Peru color
	static hopp::color peru() { return { 205u, 133u, 63u }; }
	
	/// @brief Persian pink color
	/// @return Persian pink color
	static hopp::color pink_persian() { return { 248u, 127u, 192u }; }
	
	/// @brief Persian plum color
	/// @return Persian plum color
	static hopp::color plum_persian() { return { 113u, 29u, 26u }; }
	
	/// @brief Persian red color
	/// @return Persian red color
	static hopp::color red_persian() { return { 206u, 54u, 46u }; }
	
	/// @brief Persian rose color
	/// @return Persian rose color
	static hopp::color rose_persian() { return { 255u, 41u, 164u }; }
	
	/// @brief Persimomn color
	/// @return Persimmon color
	static hopp::color persimmon() { return { 238u, 91u, 0u }; }
	
	/// @brief Phlox color
	/// @return Phlox color
	static hopp::color phlox() { return { 224u, 0u, 255u }; }
	
	/// @brief Phthalo blue color
	/// @return Phthalo blue color
	static hopp::color blue_phthalo() { return { 0u, 3u, 141u }; }
	
	/// @brief Phthalo green color
	/// @return Phthalo green color
	static hopp::color green_phthalo() { return { 17u, 53u, 35u }; }
	
	/// @brief Piggy pink color
	/// @return Piggy pink color
	static hopp::color pink_piggy() { return { 254u, 221u, 230u }; }
	
	/// @brief Pink green color
	/// @return Pine green color
	static hopp::color green_pine() { return { 0u, 121u, 111u }; }
	
	/// @brief Pink color
	/// @return Pink color
	static hopp::color pink() { return { 255u, 192u, 203u }; }
	
	/// @brief Pink-orange color
	/// @return Pink-orange color
	static hopp::color pink_orange() { return { 255u, 155u, 95u }; }
	
	/// @brief Pink pearl color
	/// @return Pink pearl color
	static hopp::color pink_pearl() { return { 232u, 172u, 208u }; }
	
	/// @brief Pink Sherbet color
	/// @return Pink Sherbet color
	static hopp::color pink_sherbet() { return { 248u, 144u, 167u }; }
	
	/// @brief Pistachio color
	/// @return Pistachio color
	static hopp::color pistachio() { return { 146u, 198u, 107u }; }
	
	/// @brief Platinum color
	/// @return Platinum color
	static hopp::color platinum() { return { 229u, 228u, 226u }; }
	
	/// @brief Plum (traditional) color
	/// @return Plum (traditional) color
	static hopp::color plum_traditional() { return { 143u, 68u, 135u }; }
	
	/// @brief Plum (web) color
	/// @return Plum (web) color
	static hopp::color plum_web() { return { 222u, 159u, 223u }; }
	
	/// @brief Portland Orange color
	/// @return Portland Orange color
	static hopp::color orange_portland() { return { 255u, 93u, 43u }; }
	
	/// @brief Powder blue (web) color
	/// @return Powder blue (web) color
	static hopp::color blue_powder_web() { return { 175u, 224u, 231u }; }
	
	/// @brief Princeton orange color
	/// @return Princeton orange color
	static hopp::color orange_princeton() { return { 255u, 145u, 0u }; }
	
	/// @brief Prune color
	/// @return Prune color
	static hopp::color prune() { return { 113u, 29u, 26u }; }
	
	/// @brief Prussian blue color
	/// @return Prussian blue color
	static hopp::color blue_prussian() { return { 0u, 48u, 85u }; }
	
	/// @brief Psychedelic purple color
	/// @return Psychedelic purple color
	static hopp::color purple_psychedelic() { return { 224u, 0u, 255u }; }
	
	/// @brief Puce color
	/// @return Puce color
	static hopp::color puce() { return { 205u, 136u, 153u }; }
	
	/// @brief Pumpkin color
	/// @return Pumpkin color
	static hopp::color pumpkin() { return { 255u, 119u, 0u }; }
	
	/// @brief Purple (HTML/CSS) color
	/// @return Purple (HTML/CSS) color
	static hopp::color purple_html_css() { return { 129u, 0u, 131u }; }
	
	/// @brief Purple (Munsell) color
	/// @return Purple (Munsell) color
	static hopp::color purple_munsell() { return { 160u, 0u, 202u }; }
	
	/// @brief Purple (X11) color
	/// @return Purple (X11) color
	static hopp::color purple_x11() { return { 160u, 12u, 246u }; }
	
	/// @brief Purple Heart color
	/// @return Purple Heart color
	static hopp::color purple_heart() { return { 105u, 50u, 159u }; }
	
	/// @brief Purple mountain majesty color
	/// @return Purple mountain majesty color
	static hopp::color purple_mountain_majesty() { return { 150u, 119u, 185u }; }
	
	/// @brief Purple pizzazz color
	/// @return Purple pizzazz color
	static hopp::color purple_pizzazz() { return { 255u, 76u, 222u }; }
	
	/// @brief Purple taupe color
	/// @return Purple taupe color
	static hopp::color purple_taupe() { return { 80u, 64u, 78u }; }
	
	/// @brief Radical Red color
	/// @return Radical Red color
	static hopp::color red_radical() { return { 255u, 57u, 92u }; }
	
	/// @brief Raspberry color
	/// @return Raspberry color
	static hopp::color raspberry() { return { 229u, 20u, 93u }; }
	
	/// @brief Raspberry glace color
	/// @return Raspberry glace color
	static hopp::color raspberry_glace() { return { 146u, 95u, 109u }; }
	
	/// @brief Raspberry pink color
	/// @return Raspberry pink color
	static hopp::color raspberry_pink() { return { 228u, 81u, 154u }; }
	
	/// @brief Raspberry rose color
	/// @return Raspberry rose color
	static hopp::color raspberry_rose() { return { 180u, 69u, 109u }; }
	
	/// @brief Raw umber color
	/// @return Raw umber color
	static hopp::color umber_raw() { return { 131u, 103u, 65u }; }
	
	/// @brief Razzle dazzle rose color
	/// @return Razzle dazzle rose color
	static hopp::color rose_razzle_dazzle() { return { 255u, 49u, 208u }; }
	
	/// @brief Razzmatazz color
	/// @return Razzmatazz color
	static hopp::color razzmatazz() { return { 229u, 40u, 107u }; }
	
	/// @brief Red color
	/// @return Red color
	static hopp::color red() { return { 255u, 19u, 0u }; }
	
	/// @brief Red (Munsell) color
	/// @return Red (Munsell) color
	static hopp::color red_munsell() { return { 244u, 16u, 56u }; }
	
	/// @brief Red (NCS) color
	/// @return Red (NCS) color
	static hopp::color red_ncs() { return { 198u, 12u, 48u }; }
	
	/// @brief Red (pigment) color
	/// @return Red (pigment) color
	static hopp::color red_pigment() { return { 239u, 35u, 25u }; }
	
	/// @brief Red (RYB) color
	/// @return Red (RYB) color
	static hopp::color red_ryb() { return { 255u, 46u, 0u }; }
	
	/// @brief Red-brown color
	/// @return Red-brown color
	static hopp::color red_brown() { return { 166u, 44u, 38u }; }
	
	/// @brief Red-violet color
	/// @return Red-violet color
	static hopp::color red_violet() { return { 200u, 22u, 135u }; }
	
	/// @brief Redwood color
	/// @return Redwood color
	static hopp::color redwood() { return { 172u, 79u, 81u }; }
	
	/// @brief Regalia color
	/// @return Regalia color
	static hopp::color regalia() { return { 82u, 43u, 131u }; }
	
	/// @brief Rich black color
	/// @return Rich black color
	static hopp::color black_rich() { return { 0u, 64u, 64u }; }
	
	/// @brief Rich brillant lavender color
	/// @return Rich brillant lavender color
	static hopp::color lavender_brilliant_rich() { return { 242u, 166u, 255u }; }
	
	/// @brief Rich carmine color
	/// @return Rich carmine color
	static hopp::color carmine_rich() { return { 217u, 12u, 62u }; }
	
	/// @brief Rich electric blue color
	/// @return Rich electric blue color
	static hopp::color blue_electric_rich() { return { 0u, 144u, 211u }; }
	
	/// @brief Rich lavender color
	/// @return Rich lavender color
	static hopp::color lavender_rich() { return { 167u, 105u, 211u }; }
	
	/// @brief Rich lilac color
	/// @return Rich lilac color
	static hopp::color lilac_rich() { return { 173u, 95u, 204u }; }
	
	/// @brief Rich maroon color
	/// @return Rich maroon color
	static hopp::color maroon_rich() { return { 177u, 49u, 96u }; }
	
	/// @brief Rifle green color
	/// @return Rifle green color
	static hopp::color green_rifle() { return { 65u, 72u, 50u }; }
	
	/// @brief Robin egg blue color
	/// @return Robin egg blue color
	static hopp::color blue_robin_egg() { return { 0u, 203u, 205u }; }
	
	/// @brief Rose color
	/// @return Rose color
	static hopp::color rose() { return { 255u, 11u, 128u }; }
	
	/// @brief Rose bonbon color
	/// @return Rose bonbon color
	static hopp::color rose_bonbon() { return { 251u, 67u, 160u }; }
	
	/// @brief Rose ebony color
	/// @return Rose ebony color
	static hopp::color rose_ebony() { return { 104u, 72u, 69u }; }
	
	/// @brief Rose gold color
	/// @return Rose gold color
	static hopp::color rose_gold() { return { 184u, 111u, 121u }; }
	
	/// @brief Rose madder color
	/// @return Rose madder color
	static hopp::color rose_madder() { return { 229u, 43u, 49u }; }
	
	/// @brief Rose pink color
	/// @return Rose pink color
	static hopp::color rose_pink() { return { 255u, 102u, 207u }; }
	
	/// @brief Rose quartz color
	/// @return Rose quartz color
	static hopp::color rose_quartz() { return { 170u, 152u, 170u }; }
	
	/// @brief Rose taupe color
	/// @return Rose taupe color
	static hopp::color rose_taupe() { return { 145u, 93u, 92u }; }
	
	/// @brief Rose vale color
	/// @return Rose vale color
	static hopp::color rose_vale() { return { 172u, 79u, 81u }; }
	
	/// @brief Rosewood color
	/// @return Rosewood color
	static hopp::color rosewood() { return { 102u, 3u, 8u }; }
	
	/// @brief Rosso corsa color
	/// @return Rosso corsa color
	static hopp::color rosso_corsa() { return { 214u, 14u, 0u }; }
	
	/// @brief Rosy brown color
	/// @return Rosy brown color
	static hopp::color brown_rosy() { return { 189u, 143u, 142u }; }
	
	/// @brief Royal azure color
	/// @return Royal azure color
	static hopp::color azure_royal() { return { 0u, 52u, 172u }; }
	
	/// @brief Royal blue (traditional) color
	/// @return Royal blue (traditional) color
	static hopp::color blue_royal_traditional() { return { 0u, 33u, 104u }; }
	
	/// @brief Royal blue (web) color
	/// @return Royal blue (web) color
	static hopp::color blue_royal_web() { return { 61u, 101u, 230u }; }
	
	/// @brief Royal fuchsia color
	/// @return Royal fuchsia color
	static hopp::color fuchsia_royal() { return { 203u, 44u, 148u }; }
	
	/// @brief Royal purple color
	/// @return Royal purple color
	static hopp::color purple_royal() { return { 120u, 79u, 172u }; }
	
	/// @brief Ruby color
	/// @return Ruby color
	static hopp::color ruby() { return { 226u, 24u, 95u }; }
	
	/// @brief Ruddy color
	/// @return Ruddy color
	static hopp::color ruddy() { return { 255u, 18u, 30u }; }
	
	/// @brief Ruddy brown color
	/// @return Ruddy brown color
	static hopp::color ruddy_brown() { return { 188u, 102u, 28u }; }
	
	/// @brief Ruddy pink color
	/// @return Ruddy pink color
	static hopp::color ruddy_pink() { return { 226u, 143u, 149u }; }
	
	/// @brief Rufous color
	/// @return Rufous color
	static hopp::color rufous() { return { 170u, 32u, 0u }; }
	
	/// @brief Russet color
	/// @return Russet color
	static hopp::color russet() { return { 129u, 71u, 19u }; }
	
	/// @brief Rust color
	/// @return Rust color
	static hopp::color rust() { return { 185u, 67u, 0u }; }
	
	/// @brief Sacramento State green color
	/// @return Sacramento State green color
	static hopp::color green_sacramento_state() { return { 0u, 86u, 62u }; }
	
	/// @brief Saddle brown color
	/// @return Saddle brown color
	static hopp::color brown_saddle() { return { 140u, 70u, 5u }; }
	
	/// @brief Safety orange color
	/// @return Safety orange color
	static hopp::color orange_safety() { return { 255u, 106u, 0u }; }
	
	/// @brief Saffron color
	/// @return Saffron color
	static hopp::color saffron() { return { 245u, 198u, 0u }; }
	
	/// @brief St. Patrick's blue color
	/// @return St. Patrick's blue color
	static hopp::color blue_saint_patrick() { return { 33u, 38u, 125u }; }
	
	/// @brief Salmon color
	/// @return Salmon color
	static hopp::color salmon() { return { 255u, 142u, 100u }; }
	
	/// @brief Salmon pink color
	/// @return Salmon pink color
	static hopp::color pink_salmon() { return { 255u, 146u, 164u }; }
	
	/// @brief Sand color
	/// @return Sand color
	static hopp::color sand() { return { 195u, 179u, 124u }; }
	
	/// @brief Sand dune color
	/// @return Sand dune color
	static hopp::color sand_dune() { return { 151u, 114u, 0u }; }
	
	/// @brief Sandstorm color
	/// @return Sandstorm color
	static hopp::color sandstorm() { return { 237u, 214u, 31u }; }
	
	/// @brief Sandy brown color
	/// @return Sandy brown color
	static hopp::color brown_sandy() { return { 246u, 165u, 88u }; }
	
	/// @brief Sandy taupe color
	/// @return Sandy taupe color
	static hopp::color taupe_sandy() { return { 151u, 114u, 0u }; }
	
	/// @brief Sangria color
	/// @return Sangria color
	static hopp::color sangria() { return { 147u, 6u, 2u }; }
	
	/// @brief Sap green color
	/// @return Sap green color
	static hopp::color green_sap() { return { 79u, 126u, 31u }; }
	
	/// @brief Sapphire color
	/// @return Sapphire color
	static hopp::color sapphire() { return { 4u, 35u, 105u }; }
	
	/// @brief Satin sheen gold color
	/// @return Satin sheen gold color
	static hopp::color gold_satin_sheen() { return { 204u, 162u, 32u }; }
	
	/// @brief Scarlet color
	/// @return Scarlet color
	static hopp::color scarlet() { return { 255u, 40u, 0u }; }
	
	/// @brief School bus yellow color
	/// @return School bus yellow color
	static hopp::color yellow_school_bus() { return { 255u, 218u, 0u }; }
	
	/// @brief Screamin' green color
	/// @return Screamin' green color
	static hopp::color green_screamin() { return { 115u, 255u, 110u }; }
	
	/// @brief Sea green color
	/// @return Sea green color
	static hopp::color green_sea() { return { 43u, 139u, 84u }; }
	
	/// @brief Seal brown color
	/// @return Seal brown color
	static hopp::color brown_seal() { return { 50u, 20u, 19u }; }
	
	/// @brief Seashell color
	/// @return Seashell color
	static hopp::color seashell() { return { 255u, 245u, 237u }; }
	
	/// @brief Selective yellow color
	/// @return Selective yellow color
	static hopp::color yellow_selective() { return { 255u, 188u, 0u }; }
	
	/// @brief Sepia color
	/// @return Sepia color
	static hopp::color sepia() { return { 113u, 67u, 10u }; }
	
	/// @brief Shadow color
	/// @return Shadow color
	static hopp::color shadow() { return { 138u, 121u, 91u }; }
	
	/// @brief Shamrock green color
	/// @return Shamrock green color
	static hopp::color green_shamrock() { return { 0u, 158u, 92u }; }
	
	/// @brief Shocking pink color
	/// @return Shocking pink color
	static hopp::color pink_shocking() { return { 254u, 11u, 195u }; }
	
	/// @brief Sienna color
	/// @return Sienna color
	static hopp::color sienna() { return { 137u, 47u, 16u }; }
	
	/// @brief Silver color
	/// @return Silver color
	static hopp::color silver() { return { 192u, 192u, 192u }; }
	
	/// @brief Sinopia color
	/// @return Sinopia color
	static hopp::color sinopia() { return { 205u, 68u, 0u }; }
	
	/// @brief Skobeloff color
	/// @return Skobeloff color
	static hopp::color skobeloff() { return { 0u, 116u, 117u }; }
	
	/// @brief Sky blue color
	/// @return Sky blue color
	static hopp::color blue_sky() { return { 133u, 205u, 237u }; }
	
	/// @brief Sky magenta color
	/// @return Sky magenta color
	static hopp::color magenta_sky() { return { 208u, 113u, 177u }; }
	
	/// @brief Slate blue color
	/// @return Slate blue color
	static hopp::color blue_slate() { return { 105u, 87u, 209u }; }
	
	/// @brief Slate gray color
	/// @return Slate gray color
	static hopp::color gray_slate() { return { 111u, 128u, 145u }; }
	
	/// @brief Smalt color
	/// @return Smalt color
	static hopp::color smalt() { return { 0u, 47u, 157u }; }
	
	/// @brief Smokey topaz color
	/// @return Smokey topaz color
	static hopp::color topaz_smokey() { return { 148u, 62u, 64u }; }
	
	/// @brief Smokey black color
	/// @return Smokey black color
	static hopp::color black_smokey() { return { 16u, 12u, 8u }; }
	
	/// @brief Snow color
	/// @return Snow color
	static hopp::color snow() { return { 255u, 250u, 250u }; }
	
	/// @brief Spiro Disco Ball color
	/// @return Spiro Disco Ball color
	static hopp::color spiro_disco_ball() { return { 0u, 190u, 255u }; }
	
	/// @brief Splashed white color
	/// @return Splashed white color
	static hopp::color white_splashed() { return { 254u, 253u, 255u }; }
	
	/// @brief Spring bud color
	/// @return Spring bud color
	static hopp::color bud_spring() { return { 166u, 253u, 0u }; }
	
	/// @brief Spring green color
	/// @return Spring green color
	static hopp::color green_spring() { return { 0u, 255u, 116u }; }
	
	/// @brief Steel blue color
	/// @return Steel blue color
	static hopp::color blue_steel() { return { 67u, 129u, 183u }; }
	
	/// @brief Stil de grain yellow color
	/// @return Stil de grain yellow color
	static hopp::color yellow_stil_de_grain() { return { 251u, 219u, 78u }; }
	
	/// @brief Straw color
	/// @return Straw color
	static hopp::color straw() { return { 229u, 218u, 100u }; }
	
	/// @brief Sunglow color
	/// @return Sunglow color
	static hopp::color sunglow() { return { 255u, 206u, 0u }; }
	
	/// @brief Sunset color
	/// @return Sunset color
	static hopp::color sunset() { return { 251u, 215u, 161u }; }
	
	/// @brief Tan color
	/// @return Tan color
	static hopp::color tan() { return { 211u, 181u, 137u }; }
	
	/// @brief Tangelo color
	/// @return Tangelo color
	static hopp::color tangelo() { return { 251u, 80u, 0u }; }
	
	/// @brief Tangerine color
	/// @return Tangerine color
	static hopp::color tangerine() { return { 244u, 135u, 0u }; }
	
	/// @brief Tangerine yellow color
	/// @return Tangerine yellow color
	static hopp::color tangerine_yellow() { return { 255u, 206u, 0u }; }
	
	/// @brief Taupe color
	/// @return Taupe color
	static hopp::color taupe() { return { 72u, 60u, 49u }; }
	
	/// @brief Taupe gray color
	/// @return Taupe gray color
	static hopp::color taupe_gray() { return { 139u, 133u, 137u }; }
	
	/// @brief Tea green color
	/// @return Tea green color
	static hopp::color green_tea() { return { 208u, 240u, 189u }; }
	
	/// @brief Tea rose (orange) color
	/// @return Tea rose (orange) color
	static hopp::color rose_tea_orange() { return { 250u, 132u, 118u }; }
	
	/// @brief Tea rose (rose) color
	/// @return Tea rose (rose) color
	static hopp::color rose_tea_rose() { return { 245u, 194u, 193u }; }
	
	/// @brief Teal color
	/// @return Teal color
	static hopp::color teal() { return { 0u, 128u, 129u }; }
	
	/// @brief Teal blue color
	/// @return Teal blue color
	static hopp::color blue_teal() { return { 51u, 116u, 137u }; }
	
	/// @brief Teal green color
	/// @return Teal green color
	static hopp::color green_teal() { return { 0u, 109u, 90u }; }
	
	/// @brief Tenné color
	/// @return Tenné color
	static hopp::color tenne() { return { 207u, 89u, 0u }; }
	
	/// @brief Terra cotta color
	/// @return Terra cotta color
	static hopp::color terra_cotta() { return { 228u, 116u, 87u }; }
	
	/// @brief Thistle color
	/// @return Thistle color
	static hopp::color thistle() { return { 216u, 191u, 217u }; }
	
	/// @brief Thulian pink color
	/// @return Thulian pink color
	static hopp::color pink_thulian() { return { 223u, 111u, 162u }; }
	
	/// @brief Tickle Me Pink color
	/// @return Tickle Me Pink color
	static hopp::color pink_tickle_me() { return { 254u, 138u, 172u }; }
	
	/// @brief Tiffany Blue color
	/// @return Tiffany Blue color
	static hopp::color blue_tiffany() { return { 0u, 186u, 182u }; }
	
	/// @brief Tiger's eye color
	/// @return Tiger's eye color
	static hopp::color tiger_eye() { return { 226u, 143u, 46u }; }
	
	/// @brief Timberwolf color
	/// @return Timberwolf color
	static hopp::color timberwolf() { return { 219u, 215u, 210u }; }
	
	/// @brief Titanium yellow color
	/// @return Titanium yellow color
	static hopp::color yellow_titanium() { return { 239u, 232u, 0u }; }
	
	/// @brief Tomato color
	/// @return Tomato color
	static hopp::color tomato() { return { 255u, 102u, 64u }; }
	
	/// @brief Toolbox color
	/// @return Toolbox color
	static hopp::color toolbox() { return { 115u, 106u, 195u }; }
	
	/// @brief Tractor red color
	/// @return Tractor red color
	static hopp::color red_tractor() { return { 255u, 26u, 47u }; }
	
	/// @brief Trolley Grey color
	/// @return Trolley Grey color
	static hopp::color grey_trolley() { return { 128u, 128u, 128u }; }
	
	/// @brief Tropical rain forest color
	/// @return Tropical rain forest color
	static hopp::color tropical_rain_forest() { return { 0u, 117u, 93u }; }
	
	/// @brief True Blue color
	/// @return True Blue color
	static hopp::color blue_true() { return { 0u, 112u, 211u }; }
	
	/// @brief Tufts Blue color
	/// @return Tufts Blue color
	static hopp::color blue_tufts() { return { 61u, 123u, 196u }; }
	
	/// @brief Tumbleweed color
	/// @return Tumbleweed color
	static hopp::color tumbleweed() { return { 223u, 171u, 133u }; }
	
	/// @brief Turkish rose color
	/// @return Turkish rose color
	static hopp::color rose_turkish() { return { 182u, 114u, 129u }; }
	
	/// @brief Turquoise color
	/// @return Turquoise color
	static hopp::color turquoise() { return { 36u, 213u, 200u }; }
	
	/// @brief Turquoise blue color
	/// @return Turquoise blue color
	static hopp::color blue_turquoise() { return { 0u, 254u, 239u }; }
	
	/// @brief Turquoise green color
	/// @return Turquoise green color
	static hopp::color green_turquoise() { return { 159u, 214u, 178u }; }
	
	/// @brief Tuscan red color
	/// @return Tuscan red color
	static hopp::color red_tuscan() { return { 131u, 54u, 52u }; }
	
	/// @brief Twilight lavender color
	/// @return Twilight lavender color
	static hopp::color lavender_twilight() { return { 139u, 73u, 108u }; }
	
	/// @brief Tyrian purple color
	/// @return Tyrian purple color
	static hopp::color purple_tyrian() { return { 103u, 3u, 61u }; }
	
	/// @brief UA blue color
	/// @return UA blue color
	static hopp::color blue_ua() { return { 0u, 46u, 174u }; }
	
	/// @brief UA red color
	/// @return UA red color
	static hopp::color red_ua() { return { 219u, 12u, 75u }; }
	
	/// @brief Ube color
	/// @return Ube color
	static hopp::color ube() { return { 136u, 119u, 198u }; }
	
	/// @brief UCLA Blue color
	/// @return UCLA Blue color
	static hopp::color blue_ucla() { return { 82u, 103u, 151u }; }
	
	/// @brief UCLA Gold color
	/// @return UCLA Gold color
	static hopp::color gold_ucla() { return { 255u, 181u, 0u }; }
	
	/// @brief UFO Green color
	/// @return UFO Green color
	static hopp::color green_ufo() { return { 54u, 208u, 105u }; }
	
	/// @brief Ultramarine color
	/// @return Ultramarine color
	static hopp::color ultramarine() { return { 13u, 0u, 147u }; }
	
	/// @brief Ultramarine blue color
	/// @return Ultramarine blue color
	static hopp::color blue_ultramarine() { return { 60u, 97u, 250u }; }
	
	/// @brief Ultra pink color
	/// @return Ultra pink color
	static hopp::color pink_ultra() { return { 255u, 109u, 255u }; }
	
	/// @brief Umber color
	/// @return Umber color
	static hopp::color umber() { return { 99u, 81u, 70u }; }
	
	/// @brief United Nations blue color
	/// @return Unated Nations blue color
	static hopp::color blue_united_nations() { return { 88u, 144u, 233u }; }
	
	/// @brief Unmellow Yellow color
	/// @return Unmellow Yellow color
	static hopp::color yellow_unmellow() { return { 255u, 255u, 81u }; }
	
	/// @brief UP Forest green color
	/// @return UP Forest green color
	static hopp::color green_up_forest() { return { 0u, 68u, 30u }; }
	
	/// @brief UP Maroon color
	/// @return UP Maroon color
	static hopp::color maroon_up() { return { 124u, 19u, 15u }; }
	
	/// @brief Upsdell red color
	/// @return Upsdell red color
	static hopp::color red_upsdell() { return { 176u, 35u, 37u }; }
	
	/// @brief Urobilin color
	/// @return Urobilin color
	static hopp::color urobilin() { return { 226u, 175u, 0u }; }
	
	/// @brief USC Cardinal color
	/// @return USC Cardinal color
	static hopp::color cardinal_usc() { return { 154u, 7u, 0u }; }
	
	/// @brief USC Gold color
	/// @return USC Gold color
	static hopp::color gold_usc() { return { 255u, 206u, 0u }; }
	
	/// @brief Utah Crimson color
	/// @return Utah Crimson color
	static hopp::color crimson_utah() { return { 213u, 12u, 61u }; }
	
	/// @brief Vanilla color
	/// @return Vanilla color
	static hopp::color vanilla() { return { 244u, 230u, 167u }; }
	
	/// @brief Vegas gold color
	/// @return Vegas gold color
	static hopp::color gold_vegas() { return { 198u, 180u, 78u }; }
	
	/// @brief Venetian red color
	/// @return Venetian red color
	static hopp::color red_venetian() { return { 202u, 18u, 8u }; }
	
	/// @brief Verdigris color
	/// @return Verdigris color
	static hopp::color verdigris() { return { 62u, 179u, 174u }; }
	
	/// @brief Vermilion color
	/// @return Vermilion color
	static hopp::color vermilion() { return { 229u, 69u, 45u }; }
	
	/// @brief Veronica color
	/// @return Veronica color
	static hopp::color veronica() { return { 160u, 12u, 246u }; }
	
	/// @brief Violet color
	/// @return Violet color
	static hopp::color violet() { return { 142u, 0u, 255u }; }
	
	/// @brief Violet (wheel) color
	/// @return Violet (wheel) color
	static hopp::color violet_wheel() { return { 126u, 0u, 255u }; }
	
	/// @brief Violet (RYB) color
	/// @return Violet (RYB) color
	static hopp::color violet_ryb() { return { 134u, 0u, 179u }; }
	
	/// @brief Violet (web) color
	/// @return Violet (web) color
	static hopp::color violet_web() { return { 239u, 129u, 242u }; }
	
	/// @brief Viridian color
	/// @return Viridian color
	static hopp::color viridian() { return { 62u, 130u, 108u }; }
	
	/// @brief Vivid auburn color
	/// @return Vivid auburn color
	static hopp::color auburn_vivid() { return { 147u, 41u, 33u }; }
	
	/// @brief Vivid burgundy color
	/// @return Vivid burgundy color
	static hopp::color burgundy_vivid() { return { 160u, 32u, 52u }; }
	
	/// @brief Vivid cerise color
	/// @return Vivid cerise color
	static hopp::color cerise_vivid() { return { 220u, 31u, 130u }; }
	
	/// @brief Vivid tangerine color
	/// @return Vivid tangerine color
	static hopp::color tangerine_vivid() { return { 255u, 161u, 134u }; }
	
	/// @brief Vivid violet color
	/// @return Vivid violet color
	static hopp::color violet_vivid() { return { 159u, 0u, 255u }; }
	
	/// @brief Warm black color
	/// @return Warm black color
	static hopp::color black_warm() { return { 0u, 66u, 66u }; }
	
	/// @brief Wenge color
	/// @return Wenge color
	static hopp::color wenge() { return { 100u, 84u, 82u }; }
	
	/// @brief Wheat color
	/// @return Wheat color
	static hopp::color wheat() { return { 246u, 223u, 176u }; }
	
	/// @brief White color
	/// @return White color
	static hopp::color white() { return { 255u, 255u, 255u }; }
	
	/// @brief White smoke color
	/// @return White smoke color
	static hopp::color white_smoke() { return { 245u, 245u, 245u }; }
	
	/// @brief Wild blue yonder color
	/// @return Wild blue yonder color
	static hopp::color blue_wild_yonder() { return { 161u, 172u, 210u }; }
	
	/// @brief Wild Strawberry color
	/// @return Wild Strawberry color
	static hopp::color strawberry_wild() { return { 255u, 68u, 166u }; }
	
	/// @brief Wild Watermelon color
	/// @return Wild Watermelon color
	static hopp::color watermelon_wild() { return { 254u, 109u, 132u }; }
	
	/// @brief Wisteria color
	/// @return Wisteria color
	static hopp::color wisteria() { return { 201u, 159u, 223u }; }
	
	/// @brief Xanadu color
	/// @return Xanadu color
	static hopp::color xanadu() { return { 115u, 134u, 119u }; }
	
	/// @brief Yale Blue color
	/// @return Yale Blue color
	static hopp::color blue_yale() { return { 5u, 75u, 149u }; }
	
	/// @brief Yellow color
	/// @return Yellow color
	static hopp::color yellow() { return { 255u, 255u, 0u }; }
	
	/// @brief Yellow (Munsell) color
	/// @return Yellow (Munsell) color
	static hopp::color yellow_munsell() { return { 240u, 206u, 0u }; }
	
	/// @brief Yellow (NCS) color
	/// @return Yellow (NCS) color
	static hopp::color yellow_ncs() { return { 255u, 213u, 0u }; }
	
	/// @brief Yellow (process) color
	/// @return Yellow (process) color
	static hopp::color yellow_process() { return { 255u, 241u, 0u }; }
	
	/// @brief Yellow (RYB) color
	/// @return Yellow (RYB) color
	static hopp::color yellow_ryb() { return { 255u, 255u, 0u }; }
	
	/// @brief Yellow-green color
	/// @return Yellow-green color
	static hopp::color yellow_green() { return { 154u, 206u, 4u }; }
	
	/// @brief Zaffre color
	/// @return Zaffre color
	static hopp::color zaffre() { return { 0u, 4u, 172u }; }
	
	/// @brief Zinnwaldite brown color
	/// @return Zinnwaldite brown color
	static hopp::color brown_zinnaldite() { return { 44u, 22u, 6u }; }
};
