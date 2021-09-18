cyan = "\e[36m"
clear = "\e[0m"
puts "Hello! What is your name?"
name = cyan + gets.chomp + clear
puts "Hi #{name}, please give me 6 adjectives, pressing enter after each word"
adj = cyan + gets.chomp + clear
adj1 = cyan + gets.chomp + clear
adj2 = cyan + gets.chomp + clear
adj3 = cyan + gets.chomp + clear
adj4 = cyan + gets.chomp + clear
adj5 = cyan + gets.chomp + clear
puts "Ok, now give me the names of two celebrities, pressing enter after each name"
celeb = cyan + gets.chomp + clear
celeb1 = cyan + gets.chomp + clear
puts "Great! Now please give me the name of an animal"
animal = cyan + gets.chomp + clear
puts "Now give me a verb"
verb = cyan + gets.chomp + clear
puts "Please give me 4 nouns, pressing enter after each one"
noun = cyan + gets.chomp + clear
noun1 = cyan + gets.chomp + clear
noun2 = cyan + gets.chomp + clear
noun3 = cyan + gets.chomp + clear
puts "Now please name 2 parts of the body, pressing enter after each"
body = cyan + gets.chomp + clear
body1 = cyan + gets.chomp + clear
puts "Please give me 2 adverbs, pressing enter after each one"
adverb = cyan + gets.chomp + clear
adverb1 = cyan + gets.chomp + clear
puts "Finally, type the name of a person in this room (male)"
male = cyan + gets.chomp + clear
puts "Calculating..."
puts "--------------------------------------"
puts "My 'Dream Man' should, first of all be very #{adj} and"
puts "#{adj1}. He should have a physique like"
puts "#{celeb}, a profile like #{celeb1}, and the"
puts "intelligence of a/an #{animal}. He must be polite and must"
puts "always remember to #{verb} my #{noun}, to"
puts "tip his #{noun1} and to take my #{body} when"
puts "crossing the street. He should move #{adverb}, have a/an"
puts "#{adj2} voice, and should always dress"
puts "#{adverb1}. i would also like him to be a/an"
puts "#{adj3} dancer, and when we are alone he should whisper"
puts "#{adj4} nothings into my #{body1} and hold"
puts "my #{adj5} #{noun2}. I know a/an"
puts "#{noun3} is hard to find. In fact the only one I can think of is"
puts "#{male}"
