import discord
intents = discord.Intents.all()
client = discord.Client(command_prefix='!', intents=intents)
 
@client.event
async def on_ready():
    print('We have logged in as {0.user}'.format(client))
 
@client.event
async def on_message(message):
    if message.author == client.user:
        return
    
    if message.content.startswith('testbench'):
        await message.channel.send('thats my name')
 
    if message.content.startswith('/funny'):
        
        await message.channel.send('/tts <Insert Something Funny here>')


 
client.run("MTA3MDE0Njc0MDYzMzczMTE1NQ.GitZGA.Z10rcSnEFyyeyuoNDIlvlfnfM1_mmZXdKmS8cA")