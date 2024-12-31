#pragma once
#include <iostream>

// noexcept�� �ش� �Լ����� ���ܸ� ������ �ʴ´ٴ� ���� ����ϴ� Ű������.
// ���� �̰� ���ٸ� �����Ϸ��� ����ȭ�� ������ �Ͼ �� �ֱ� ������ �̵� �����ڸ� ȣ������ �ʰ�
// ���簡 �Ͼ ���� ����.
// �̸� ����������ν� �����Ϸ��� ���ϰ� ����ȭ�� �� �� ����.
class DefaultClass
{
public:

    // Constructor.
    // explicit�� �ٴ� ������ �Ͻ��� ����ȯ�� �Ͼ�� �ʰ� �������ִ� Ű����.
    explicit DefaultClass()
    {
    }

    // Destructor.
    // �Ļ� Ŭ������ �ִٸ� virtual ���̱�.
    ~DefaultClass() noexcept
    {
        std::cout << "�Ҹ��� ȣ��" << std::endl;
    }

    // Copy constructor. ���� ������
    // ���� �����ڴ� const reference�� ���ڷ� ������ L-value Ȥ�� R-value�� ���� �� ����.
    DefaultClass(const DefaultClass& other)
    {
        std::cout << "���� ������ ȣ��" << std::endl;
    }

    // Move constructor. �̵� ������
    // �̵� �����ڴ� &&�� R-value�� ����. ���ο��� move�� �ʿ��� ��ü��� move�ϰ�, �⺻ �ڷ����̶�� ����.
    DefaultClass(DefaultClass&& other) noexcept
    {
        std::cout << "�̵� ������ ȣ��" << std::endl;
    }

    // Move assignment operator. �̵� ������
    DefaultClass& operator=(DefaultClass&& other) noexcept
    {
        std::cout << "�̵� ������ ȣ��"<< std::endl;

        if (this != &other)
        {

        }
        return *this;
    }

    // Copy assignment operator.
    DefaultClass& operator=(const DefaultClass& other)
    {
        std::cout << "���� ������ ȣ��" << std::endl;

        if (this != &other)
        {

        }
        return *this;
    }

private:

};
