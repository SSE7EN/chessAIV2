#ifndef _MEMPOOLIMPL_HPP_
#define _MEMPOOLIMPL_HPP_
/**
**************************
* @file    mempoolImpl.hpp
* @author  SE7EN
* @date    2021-05-20
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "mempool.hpp"






/************************************* Defines *************************************/






/************************************* Classes *************************************/

/************************************* Implementation ******************************/
template <typename T1,typename T2,typename T3,typename T4>
MempoolManager<T1,T2,T3,T4>::MempoolManager(){
	this->mempool1.blockSize = sizeof(mempoolBlockS<T1>);
	this->mempool2.blockSize = sizeof(mempoolBlockS<T2>);
	this->mempool3.blockSize = sizeof(mempoolBlockS<T3>);
	this->mempool4.blockSize = sizeof(mempoolBlockS<T4>);
};

template <typename T1,typename T2,typename T3,typename T4>
MempoolManager<T1,T2,T3,T4>::~MempoolManager(){
	free(this->mempool1.memory);
	free(this->mempool2.memory);
	free(this->mempool3.memory);
	free(this->mempool4.memory);
};

template<typename T>
void initMempool(mempoolS<T>& mempool)
{
    uint8_t* iter = mempool.memory;
	uint8_t* end = iter + mempool.blockCount*mempool.blockSize;

	while(iter < end){
		mempoolBlockS<T>* const currentBlock = (mempoolBlockS<T>*)iter;
		currentBlock->prev = nullptr;

		if(mempool.freeBlocks != nullptr){
			mempool.freeBlocks->prev = currentBlock;
			currentBlock->next = mempool.freeBlocks;
		};
		mempool.freeBlocks = currentBlock;

		iter += mempool.blockSize;
	}

}

template <typename T1,typename T2,typename T3,typename T4>
void MempoolManager<T1,T2,T3,T4>::init(size_t blockCount1,size_t blockCount2,size_t blockCount3,size_t blockCount4)
{
	if(blockCount <= 0) return -1;
    uint8_t* temp =  (uint8_t*)malloc(sizeof(mempoolBlockS<T1>)*blockCount1 + sizeof(mempoolBlockS<T2>)*blockCount2 + sizeof(mempoolBlockS<T2>)*blockCount2 +sizeof(mempoolBlockS<T3>)*blockCount3);

	this->mempool1.memory = temp;
	this->mempool1.blockSize = sizeof(mempoolBlockS<T1>);
	this->mempool1.blockCount = blockCount1;

    this->init(this->mempool1);

    this->mempool2.memory = this->mempool1.memory + this->mempool1.blockCount*this->mempool1.blockSize;
	this->mempool2.blockSize = sizeof(mempoolBlockS<T2>);
	this->mempool2.blockCount = blockCount1;

    this->init(this->mempool2);

    this->mempool3.memory = this->mempool2.memory + this->mempool2.blockCount*this->mempool2.blockSize;
	this->mempool3.blockSize = sizeof(mempoolBlockS<T2>);
	this->mempool3.blockCount = blockCount1;

    this->init(this->mempool3);

    this->mempool4.memory = this->mempool3.memory + this->mempool3.blockCount*this->mempool3.blockSize;
	this->mempool4.blockSize = sizeof(mempoolBlockS<T2>);
	this->mempool4.blockCount = blockCount1;

    this->init(this->mempool4);


};

template <typename T1,typename T2,typename T3,typename T4>
void MempoolManager<T1,T2,T3,T4>::freeBlock(mempoolBlockS<T1> *block){
	if(this->mempool1.blockCount > 0){
		if(block->prev != nullptr){
			block->prev->next = block->next;
		}
		else{
			this->mempool1.allocatedBlocks = block->next;
		}

		if(block->next != nullptr){
			block->next->prev = block->prev;
		}

		block->next = this->mempool1.freeBlocks;
		block->prev = nullptr;

		if(this->mempool1.freeBlocks != nullptr){
			this->mempool.freeBlocks->prev = block;
		}

		this->mempool1.freeBlocks = block;	
	}
	
};

template <typename T1,typename T2,typename T3,typename T4>
mempoolBlockS<T1>* MempoolManager<T1,T2,T3,T4>::allocateBlock(T1 data){
	mempoolBlockS<T1> *block = nullptr;
	
	if(this->mempool1.freeBlocks != nullptr){
		block = this->mempool1.freeBlocks;
		this->mempool1.freeBlocks = block->next;
		this->mempool1.freeBlocks->prev = nullptr;

		block->data = data;

		if(this->mempool1.allocatedBlocks != nullptr){
			block->next = this->mempool1.allocatedBlocks;
			this->mempool1.allocatedBlocks->prev = block;
		}
		else{
			block->next = nullptr;
			block->prev = nullptr;
		}
		this->mempool1.allocatedBlocks = block;

	}


	return block;
}
template <typename T1,typename T2,typename T3,typename T4>
mempoolBlockS<T1>* MempoolManager<T1,T2,T3,T4>::allocateBlock1(){
	mempoolBlockS<T1> *block = nullptr;
	
	if(this->mempool1.freeBlocks != nullptr){
		block = this->mempool1.freeBlocks;
		this->mempool1.freeBlocks = block->next;
		this->mempool1.freeBlocks->prev = nullptr;


		if(this->mempool1.allocatedBlocks != nullptr){
			block->next = this->mempool1.allocatedBlocks;
			this->mempool1.allocatedBlocks->prev = block;
		}
		else{
			block->next = nullptr;
			block->prev = nullptr;
		}
		this->mempool1.allocatedBlocks = block;

	}


	return block;
}


template <typename T1,typename T2,typename T3,typename T4>
void MempoolManager<T1,T2,T3,T4>::freeBlock(mempoolBlockS<T2> *block){
	if(this->mempool2.blockCount > 0){
		if(block->prev != nullptr){
			block->prev->next = block->next;
		}
		else{
			this->mempool2.allocatedBlocks = block->next;
		}

		if(block->next != nullptr){
			block->next->prev = block->prev;
		}

		block->next = this->mempool2.freeBlocks;
		block->prev = nullptr;

		if(this->mempool2.freeBlocks != nullptr){
			this->mempool.freeBlocks->prev = block;
		}

		this->mempool2.freeBlocks = block;	
	}
	
};

template <typename T1,typename T2,typename T3,typename T4>
mempoolBlockS<T2>* MempoolManager<T1,T2,T3,T4>::allocateBlock(T2 data){
	mempoolBlockS<T2> *block = nullptr;
	
	if(this->mempool2.freeBlocks != nullptr){
		block = this->mempool2.freeBlocks;
		this->mempool2.freeBlocks = block->next;
		this->mempool2.freeBlocks->prev = nullptr;

		block->data = data;

		if(this->mempool2.allocatedBlocks != nullptr){
			block->next = this->mempool2.allocatedBlocks;
			this->mempool2.allocatedBlocks->prev = block;
		}
		else{
			block->next = nullptr;
			block->prev = nullptr;
		}
		this->mempool2.allocatedBlocks = block;

	}


	return block;
}
template <typename T1,typename T2,typename T3,typename T4>
mempoolBlockS<T2>* MempoolManager<T1,T2,T3,T4>::allocateBlock2(){
	mempoolBlockS<T2> *block = nullptr;
	
	if(this->mempool2.freeBlocks != nullptr){
		block = this->mempool2.freeBlocks;
		this->mempool2.freeBlocks = block->next;
		this->mempool2.freeBlocks->prev = nullptr;


		if(this->mempool2.allocatedBlocks != nullptr){
			block->next = this->mempool2.allocatedBlocks;
			this->mempool2.allocatedBlocks->prev = block;
		}
		else{
			block->next = nullptr;
			block->prev = nullptr;
		}
		this->mempool2.allocatedBlocks = block;

	}


	return block;
}

template <typename T1,typename T2,typename T3,typename T4>
void MempoolManager<T1,T2,T3,T4>::freeBlock(mempoolBlockS<T3> *block){
	if(this->mempool3.blockCount > 0){
		if(block->prev != nullptr){
			block->prev->next = block->next;
		}
		else{
			this->mempool3.allocatedBlocks = block->next;
		}

		if(block->next != nullptr){
			block->next->prev = block->prev;
		}

		block->next = this->mempool3.freeBlocks;
		block->prev = nullptr;

		if(this->mempool3.freeBlocks != nullptr){
			this->mempool.freeBlocks->prev = block;
		}

		this->mempool3.freeBlocks = block;	
	}
	
};

template <typename T1,typename T2,typename T3,typename T4>
mempoolBlockS<T3>* MempoolManager<T1,T2,T3,T4>::allocateBlock(T3 data){
	mempoolBlockS<T3> *block = nullptr;
	
	if(this->mempool3.freeBlocks != nullptr){
		block = this->mempool3.freeBlocks;
		this->mempool3.freeBlocks = block->next;
		this->mempool3.freeBlocks->prev = nullptr;

		block->data = data;

		if(this->mempool3.allocatedBlocks != nullptr){
			block->next = this->mempool3.allocatedBlocks;
			this->mempool3.allocatedBlocks->prev = block;
		}
		else{
			block->next = nullptr;
			block->prev = nullptr;
		}
		this->mempool3.allocatedBlocks = block;

	}


	return block;
}

template <typename T1,typename T2,typename T3,typename T4>
mempoolBlockS<T3>* MempoolManager<T1,T2,T3,T4>::allocateBlock3(){
	mempoolBlockS<T3> *block = nullptr;
	
	if(this->mempool3.freeBlocks != nullptr){
		block = this->mempool3.freeBlocks;
		this->mempool3.freeBlocks = block->next;
		this->mempool3.freeBlocks->prev = nullptr;


		if(this->mempool3.allocatedBlocks != nullptr){
			block->next = this->mempool3.allocatedBlocks;
			this->mempool3.allocatedBlocks->prev = block;
		}
		else{
			block->next = nullptr;
			block->prev = nullptr;
		}
		this->mempool3.allocatedBlocks = block;

	}


	return block;
}

template <typename T1,typename T2,typename T3,typename T4>
void MempoolManager<T1,T2,T3,T4>::freeBlock(mempoolBlockS<T4> *block){
	if(this->mempool4.blockCount > 0){
		if(block->prev != nullptr){
			block->prev->next = block->next;
		}
		else{
			this->mempool4.allocatedBlocks = block->next;
		}

		if(block->next != nullptr){
			block->next->prev = block->prev;
		}

		block->next = this->mempool4.freeBlocks;
		block->prev = nullptr;

		if(this->mempool4.freeBlocks != nullptr){
			this->mempool4.freeBlocks->prev = block;
		}

		this->mempool4.freeBlocks = block;	
	}
	
};

template <typename T1,typename T2,typename T3,typename T4>
mempoolBlockS<T4>* MempoolManager<T1,T2,T3,T4>::allocateBlock(T4 data){
	mempoolBlockS<T4> *block = nullptr;
	
	if(this->mempool4.freeBlocks != nullptr){
		block = this->mempool4.freeBlocks;
		this->mempool4.freeBlocks = block->next;
		this->mempool4.freeBlocks->prev = nullptr;

		block->data = data;

		if(this->mempool4.allocatedBlocks != nullptr){
			block->next = this->mempool4.allocatedBlocks;
			this->mempool4.allocatedBlocks->prev = block;
		}
		else{
			block->next = nullptr;
			block->prev = nullptr;
		}
		this->mempool4.allocatedBlocks = block;

	}


	return block;
}
template <typename T1,typename T2,typename T3,typename T4>
mempoolBlockS<T4>* MempoolManager<T1,T2,T3,T4>::allocateBlock4(){
	mempoolBlockS<T4> *block = nullptr;
	
	if(this->mempool4.freeBlocks != nullptr){
		block = this->mempool4.freeBlocks;
		this->mempool4.freeBlocks = block->next;
		this->mempool4.freeBlocks->prev = nullptr;

		if(this->mempool4.allocatedBlocks != nullptr){
			block->next = this->mempool4.allocatedBlocks;
			this->mempool4.allocatedBlocks->prev = block;
		}
		else{
			block->next = nullptr;
			block->prev = nullptr;
		}
		this->mempool4.allocatedBlocks = block;

	}


	return block;
}


#endif