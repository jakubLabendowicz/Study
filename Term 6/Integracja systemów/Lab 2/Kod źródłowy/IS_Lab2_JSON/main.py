import yaml
from deserialize_json import DeserializeJson
from serialize_json import SerializeJson
from convert_json_to_yaml import ConvertJsonToYaml
import time

def jsonDeserialization():
    newDeserializator = DeserializeJson(confdata['paths']['source_folder']+confdata['paths']['json_source_file'])
    newDeserializator.zbudujWojewodztwa()
    newDeserializator.zbudujTypy()
    newDeserializator.Z233()

def objectJsonSerialization():
    newDeserializator2 = DeserializeJson(confdata['paths']['source_folder'] + confdata['paths']['json_source_file'])
    SerializeJson.run(newDeserializator2, confdata['paths']['source_folder']+confdata['paths']['json_destination_file'])

def fileJsonSerialization():
    yield

def objectYamlConversion():
    newDeserializator3 = DeserializeJson(confdata['paths']['source_folder']+confdata['paths']['json_destination_file'])
    ConvertJsonToYaml.run(newDeserializator3, confdata['paths']['source_folder']+confdata['paths']['yaml_destination_file'])

def fileYamlConversion():
    ConvertJsonToYaml.run(confdata['paths']['source_folder']+confdata['paths']['json_destination_file'], confdata['paths']['source_folder']+confdata['paths']['yaml_destination_file'])



tempconffile = open('Assets/basic_config.yaml', encoding="utf8")
confdata = yaml.load(tempconffile, Loader=yaml.FullLoader)

queue = confdata['queue']
sortedQueueIndexes = sorted(queue)
doneQueue = []
for i in sortedQueueIndexes:
    doneQueue.append(queue[i])

for element in doneQueue:
    if element['action'] == 'jsonDeserialization' and element['active'] == True:
        jsonDeserialization()
    elif element['action'] == 'jsonSerialization' and element['active'] == True and element['type'] == 'object':
        objectJsonSerialization()
    elif element['action'] == 'jsonSerialization' and element['active'] == True and element['type'] == 'file':
        fileJsonSerialization()
    elif element['action'] == 'yamlConversion' and element['active'] == True and element['type'] == 'object':
        objectYamlConversion()
    elif element['action'] == 'yamlConversion' and element['active'] == True and element['type'] == 'file':
        fileYamlConversion()

time.sleep(60)