# Automatically generated by pb2py
from protobuf import protobuf as p
from .TxRequestDetailsType import TxRequestDetailsType
from .TxRequestSerializedType import TxRequestSerializedType
t = p.MessageType()
t.add_field(1, 'request_type', p.UVarintType)
t.add_field(2, 'details', p.EmbeddedMessage(TxRequestDetailsType))
t.add_field(3, 'serialized', p.EmbeddedMessage(TxRequestSerializedType))
TxRequest = t
TYPE = const(21)