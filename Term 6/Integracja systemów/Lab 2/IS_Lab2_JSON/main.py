print("hey, it's me - Python!")
from deserialize_json import DeserializeJson
newDeserializator = DeserializeJson('Assets/data.json')
newDeserializator.somestats('dolnośląskie', 'GM')
newDeserializator.zbudujWojewodztwa()
newDeserializator.zbudujTypy()
newDeserializator.Z233()
"""
from serialize_json import SerializeJson
SerializeJson.run(newDeserializator, 'Assets/data_mod.json')
"""
"""
from convert_json_to_yaml import ConvertJsonToYaml
ConvertJsonToYaml.run(newDeserializator,
'Assets/data_mod.json')
"""