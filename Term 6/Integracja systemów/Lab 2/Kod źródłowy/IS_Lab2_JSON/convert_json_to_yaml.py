# -*- coding: utf-8 -*-
"""
json to yaml converter
"""
import yaml

from deserialize_json import DeserializeJson
from multipledispatch import dispatch


class ConvertJsonToYaml:
 @staticmethod
 @dispatch(DeserializeJson, str)
 def run(deserializeddata, destinationfilelocaiton):
     print("let's convert something")
     with open(destinationfilelocaiton, 'w', encoding='utf8') as f:
        yaml.dump(deserializeddata, f, allow_unicode=True)
     print("it is done")

 @staticmethod
 @dispatch(str, str)
 def run(filelocation, destinationfilelocaiton):
     newDeserializator2 = DeserializeJson(filelocation)
     print("let's convert something")
     with open(destinationfilelocaiton, 'w', encoding='utf8') as f:
        yaml.dump(newDeserializator2, f, allow_unicode=True)
     print("it is done")