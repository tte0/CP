import random
import hashlib
import base64

def generate_website_link(num1, num2):
    base_url = "https://www.mkutay.dev"
    
    combined = str(num1) + str(num2) # "3742"
    
    # Create a more cryptic path using base64 encoding
    path_bytes = combined.encode('utf-8')
    encoded_path = base64.b64encode(path_bytes).decode('utf-8').rstrip('=')
    
    # Create the final URL
    website_url = f"{base_url}/amFuZS1wZWFjb2NrCg=={encoded_path}"
    
    return website_url

def generate_secret_key(num1, num2, secret_phrase="douglas adams was right"):
    """Generate a secret key using the numbers and a hidden phrase"""
    key_material = f"{num1}-{secret_phrase}-{num2}"
    
    hash_object = hashlib.sha256(key_material.encode())
    hex_hash = hash_object.hexdigest()
    
    # Take first 16 characters for the key
    secret_key = hex_hash[:16].upper()
    
    return secret_key

def check_for_combined_numbers(msg):
    """Check if message contains both 37 and 42 in the right context"""
    has_37 = "37" in msg
    has_42 = "42" in msg
    
    # Check for special combination phrases
    combination_phrases = [
      "37 42", "42 37", "37+42", "42+37", 
      "37 and 42", "42 and 37", "3742", "4237",
      "42 ve 37", "37 ve 42", "37 ile 42", "42 ile 37",
      "37-42", "42-37", "37_42", "42_37",
    ]
    
    has_combination = any(phrase in msg for phrase in combination_phrases)
    
    return has_37 and has_42, has_combination

async def arg(message):
  msg = message.content.lower()
  
  has_both_numbers, has_combination = check_for_combined_numbers(msg)
  
  # Special easter egg for the secret key
  if "douglas adams" in msg or "hitchhiker" in msg or "meaning of life" in msg or \
    "life universe everything" in msg or "best number" in msg or "best number ever" in msg \
    or "the sacred one" in msg or "the answer to everything" in msg or "bbkggh" in msg \
    or "bbkgğ" in msg or "ankara" in msg or "kayseri" in msg: 
    if has_both_numbers:
      secret_key = generate_secret_key(37, 42)
      await message.channel.send(
        f"**CLASSIFIED ACCESS GRANTED**\n"
        f"*HE* knew the truth all along...\n"
        f"Your key: `{secret_key}`\n"
        f"*Guard this with your life. The simulation is watching.*"
      )
      return
    else:
      await message.channel.send(
        "You're on the right track, but you're missing something important...\n"
        "*t h e a n s w e r s t o e v e r y t h i n g*\n"
      )
      return
  
  if has_both_numbers and has_combination:
    website_url = generate_website_link(37, 42)
    await message.channel.send(
      f"**THE PORTAL HAS OPENED**\n"
      f"You have discovered the SACRED numbers!\n"
      f"Enter here: {website_url}\n"
      f"But, what is the ?key="
    )
    return
  
  
  if "arg" in msg or "ARG" in msg or "hint" in msg or "clue" in msg or "ipucu" in msg:
    responses = [
      "ARG? The rabbit hole goes deeper than you think...\nBut the path forward is encrypted...",
      "You've found the first clue. But where's the key?",
      "ARG? Someone's been asking the right questions... \nWhat is the meaning of life?",
      "The simulation has noticed you. Prove your worth first...",
      "Is this even real? Or just a figment of your imagination?",
      "This is definitely a red herring.",
      "Do you remember what Douglas Adams said about [REDACTED]?",
      "Birinci asamadan 37 gun sonra...",
      "2^5",
      "What is the best time of day?",
      "Why is 60 seconds in a minute?",
      "998244353",
      "En sevdigimiz asal sayi",
      "I've never been to Konya actually, but I hear it's nice.",
      "The answer to life, the universe, and everything...",
      "Sometimes you need to combine things to unlock the truth...",
      "Find them both.",
    ]
    await message.channel.send(random.choice(responses))
  
  elif "github" in msg.lower():
    await message.channel.send(
      random.choice([
        "FUCK",
        "You will never find the repo, though",
      ])
    )

  elif "23" in msg:
    responses = [
      "Bu ARG'ye 23'u koyacagimi mi zannettin gercekten?",
      "Nope. Nope, nope, nope, nope.",
      "23? Really?",
      "L",
    ]
    await message.channel.send(random.choice(responses))
  
  elif "37" in msg:
    responses = [
      "23'culer aglasin, cunku cidden 37'ye ihtiyacin var.",
      "37 cok guzel bir sayidir.",
      "37 * 3 = 111",
      "37 is prime.",
      "23 + 37 = 60",
      "73 is also prime",
      "3 + 7 = 10 which is cool",
      "37 is the *actual* answer to everything, see: Veritasium",
      "37 * 2 - 1 = 73",
      "37 is important, but it's not complete without [ENGELLENMIS].",
      "1/2",
    ]
    await message.channel.send(random.choice(responses))

  elif "111" in msg:
    await message.channel.send(
      "37 * 3 = 111"
    )

  elif "60" in msg:
    await message.channel.send(random.choice([
      "23 + 37 = 60",
      "23:37"
    ]))
  
  elif "73" in msg:
    await message.channel.send(
      "73 is prime, and also 37 reversed."
    )
  
  elif "42" in msg:
    responses = [
      "Maybe it was a red herring...",
      "You have found THE MEANING!",
      "1415926535",
      "42 is the answer to life, the universe, and everything!",
      "But 42 alone isn't enough...",
      "The Hitchhiker's Guide mentions 42, yes.",
    ]
    await message.channel.send(
      random.choice(responses)
    )
  
  elif "pi" in msg or "π" in msg or "pie" in msg:
    await message.channel.send(random.choice([
      "Nope.",
      "Sugar won't help you here.",
      "I love me some pie, but not this time."
    ]))

print(generate_website_link(37, 42))
print(generate_secret_key(37, 42))