
template <class Clau, class Valor>
class NodeHeap
{
public:
    NodeHeap(const Clau &key, const Valor &v);
    virtual ~NodeHeap(){};
    void setKey(const Clau &key);
    void setValue(const Valor &value);
    const Clau &getKey() const;
    const Valor &getValue() const;

private:
    Clau key;
    Valor value;
};

template <class Clau, class Valor>
NodeHeap<Clau, Valor>::NodeHeap(const Clau &key, const Valor &v)
{
    this->key = key;
    this->value = v;
}

template <class Clau, class Valor>
void NodeHeap<Clau, Valor>::setKey(const Clau &key)
{
    this->key = key;
}
template <class Clau, class Valor>
void NodeHeap<Clau, Valor>::setValue(const Valor &value)
{
    this->value = value;
}

template <class Clau, class Valor>
const Clau &NodeHeap<Clau, Valor>::getKey() const
{
    return key;
}
template <class Clau, class Valor>
const Valor &NodeHeap<Clau, Valor>::getValue() const
{
    return value;
}
